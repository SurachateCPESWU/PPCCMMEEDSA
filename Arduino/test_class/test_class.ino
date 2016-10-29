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
        if (digitalRead(dir)== HIGH) {
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
    }

  public: void G1(double point) {
      double temp = point - axis_position ;
      Serial.println(temp);
      
      if(temp < 0) {
        setDir(false);
        digitalWrite(dir, HIGH);
      } else {
        setDir(true);
        digitalWrite(dir, LOW);
      }
      
      setStep(fabs(temp) / distancePerStep);
      move_enable = true;
    }

  public: double where() {
      return axis_position;
    }

};



Axis x(10, 11, 236);
Axis y(12, 13, 176);

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

TimedAction timedAction_x = TimedAction(1200, check_x);
TimedAction timedAction_y = TimedAction(750, check_y);




void setup() {

  Serial.begin(9600);

}


int count, temp_position;

void loop() {

  while (Serial.available() == 0) { }
  String cmd_input = Serial.readString() ;
  cmd_input.replace(" ", "");
  cmd_input.toUpperCase();;

  if (cmd_input[0] == 'G') {
    if (cmd_input[1] == '1') {

      if (cmd_input.indexOf('X') != -1) {
        count = 1;
        temp_position = cmd_input.indexOf('X');
        while ( (temp_position + count < cmd_input.length()) && ((cmd_input.charAt(temp_position + count) == '0') || (cmd_input.charAt(temp_position + count) == '1')
                || (cmd_input.charAt(temp_position + count) == '2') || (cmd_input.charAt(temp_position + count) == '3') || (cmd_input.charAt(temp_position + count) == '4')
                || (cmd_input.charAt(temp_position + count) == '5') || (cmd_input.charAt(temp_position + count) == '6') || (cmd_input.charAt(temp_position + count) == '7')
                || (cmd_input.charAt(temp_position + count) == '8') || (cmd_input.charAt(temp_position + count) == '9') || (cmd_input.charAt(temp_position + count) == '.')
                || (cmd_input.charAt(temp_position + count) == '-'))) {
          count++;
        }
        double CMD_X = (cmd_input.substring(temp_position + 1, temp_position + count)).toFloat() ;
        x.G1(CMD_X);
      }

      if (cmd_input.indexOf('Y') != -1) {
        count = 1;
        temp_position = cmd_input.indexOf('Y');
        while ( (temp_position + count < cmd_input.length()) && ((cmd_input.charAt(temp_position + count) == '0') || (cmd_input.charAt(temp_position + count) == '1')
                || (cmd_input.charAt(temp_position + count) == '2') || (cmd_input.charAt(temp_position + count) == '3') || (cmd_input.charAt(temp_position + count) == '4')
                || (cmd_input.charAt(temp_position + count) == '5') || (cmd_input.charAt(temp_position + count) == '6') || (cmd_input.charAt(temp_position + count) == '7')
                || (cmd_input.charAt(temp_position + count) == '8') || (cmd_input.charAt(temp_position + count) == '9') || (cmd_input.charAt(temp_position + count) == '.')
                || (cmd_input.charAt(temp_position + count) == '-'))) {
          count++;
        }
        double CMD_Y = (cmd_input.substring(temp_position + 1, temp_position + count)).toFloat() ;
        y.G1(CMD_Y);
      }
      
    }
  }


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
