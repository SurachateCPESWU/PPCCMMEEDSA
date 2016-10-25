#include <TimedAction.h>


class Axis {
    int sep, dir = 0 ;
    boolean state_step = false;
    int step_count = 0;
  public: Axis(int insep, int indir) {
      sep = insep;
      dir = indir;
      pinMode(sep, OUTPUT);
      pinMode(dir, OUTPUT);

    }


  public: void setStep(int setStep) {
      step_count = setStep;
    }


  public: void moveTo() {
      if (state_step == false) {
        digitalWrite(sep, HIGH);
        state_step = true;
        step_count--;
      } else {
        digitalWrite(sep, LOW);
        state_step = false;
        step_count--;
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



};



Axis x(10, 11);
Axis y(12, 13);

void gogox() {
  x.moveTo();
}

void gogoy() {
  y.moveTo();
}

TimedAction timedAction = TimedAction(5, gogox);
TimedAction timedAction2 = TimedAction(17, gogoy);
void setup() {

  Serial.begin(9600);

}

void loop() {

  timedAction.check();
  timedAction2.check();
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
