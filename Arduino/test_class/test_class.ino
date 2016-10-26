#include <TimedAction.h>


class Axis {
    int sep, dir =  0 ;
    boolean state_step = false;
  public : double  distancePerStep;
  public: double axis_position = 0;
  public: int step_count = 0;
  public: boolean move_enable = false;
  public: Axis(int insep, int indir, int in_step_per_inc) {
      sep = insep;
      dir = indir;
      pinMode(sep, OUTPUT);
      pinMode(dir, OUTPUT);
      distancePerStep = (double) 1 / (double)in_step_per_inc;
    }


  public: void setStep(int setStep) {
      step_count = setStep;
    }


  public: void moveTo() {
      if (state_step == false) {
        digitalWrite(sep, HIGH);
        state_step = true;
      } else {
        digitalWrite(sep, LOW);
        state_step = false;
        step_count--;
        if (dir == true) {
          axis_position = axis_position - distancePerStep;
        } else {
          axis_position = axis_position + distancePerStep;
        }

      }
    }

  public: void setDir(boolean dir) {
      if (dir == true) {
        digitalWrite(dir, LOW);
      } else {
        digitalWrite(dir, HIGH);
      }
      delay(100);
    }

  public: void G1(double point) {
      double temp = axis_position - point ;
      setStep(fabs(temp) / distancePerStep);
      //      setStep(100);
      if (temp > 0) {
        setDir(false);
      } else {
        setDir(true);
      }
      move_enable = true;
    }

  public: double where() {
      return axis_position;
    }

};



Axis x(10, 11, 600);
Axis y(12, 13, 173);

void check_x() {
  if (x.step_count > 0) {
    x.moveTo();
  }
}

void check_y() {
  if (y.step_count > 0) {
    y.moveTo();
  }
}

TimedAction timedAction_x = TimedAction(5000, check_x);
TimedAction timedAction_y = TimedAction(17000, check_y);




void setup() {

  Serial.begin(9600);

}

void loop() {

  x.G1(1);
  timedAction_x.reset();
  timedAction_y.reset();
  Serial.println("Start");
  Serial.println(x.where());
  Serial.println(y.where());

  // น่าจะเป็นส่วนหนึงของ main
  while (x.move_enable == true || y.move_enable == true ) {
    timedAction_x.check();
    timedAction_y.check();
    if (x.step_count == 0) {
      x.move_enable = false;
    }
    if (y.step_count == 0) {
      y.move_enable = false;
    }
  }
  y.G1(1);
  Serial.println(x.where());
  Serial.println(y.where());
  Serial.println("END");


  //  x.setDir(true);
  //  y.setDir(true);
  //  for (int i = 0 ; i <= 600 ; i++) {
  //    x.moveTo();
  //    y.moveTo();
  //    delay(15);
  //  }
  //  x.setDir(false);
  //  y.setDir(false);
  //  for (int i = 0 ; i <= 600 ; i++) {
  //    x.moveTo();
  //    y.moveTo();
  //    delay(15);
  //  }

}
