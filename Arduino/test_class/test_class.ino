class Axis_X {
    int Cx, Cy, sepX, dirX = 0 ;
    boolean state_step = false;
    int step_count = 0;
  public: Axis_X(int insepX, int indirX) {
      sepX = insepX;
      dirX = indirX;
      pinMode(sepX, OUTPUT);
      pinMode(dirX, OUTPUT);


    }

  public: void setOrigin() {
      Cx = 0 ;
      Cy = 0 ;
    }

  public: void setStep(int setStep) {
      step_count = setStep;
    }

  public: String where() {
      return Cx + "," + Cy;
    }

  public: void moveTo() {
      if (state_step == false) {
        digitalWrite(sepX, HIGH);
        state_step = true;
        step_count--;
      } else {
        digitalWrite(sepX, LOW);
        state_step = false;
        step_count--;
      }
    }

  public: void setDir(boolean dir) {
      if (dir == true) {
        digitalWrite(dirX, LOW);
      } else {
        digitalWrite(dirX, HIGH);
      }
      delay(100);
    }

};


class Axis_Y {
    int Cx, Cy, sepX, dirX = 0 ;
    boolean state_step = false;
    int step_count = 0;
  public: Axis_Y(int insepX, int indirX) {
      sepX = insepX;
      dirX = indirX;
      pinMode(sepX, OUTPUT);
      pinMode(dirX, OUTPUT);


    }

  public: void setOrigin() {
      Cx = 0 ;
      Cy = 0 ;
    }

  public: void setStep(int setStep) {
      step_count = setStep;
    }

  public: String where() {
      return Cx + "," + Cy;
    }

  public: void moveTo() {
      if (state_step == false) {
        digitalWrite(sepX, HIGH);
        state_step = true;
        step_count--;
      } else {
        digitalWrite(sepX, LOW);
        state_step = false;
        step_count--;
      }
    }

  public: void setDir(boolean dir) {
      if (dir == true) {
        digitalWrite(dirX, LOW);
      } else {
        digitalWrite(dirX, HIGH);
      }
      delay(100);
    }

};

Axis_X x(10, 11);
Axis_Y y(12, 13);
void setup() {

  Serial.begin(9600);

}

void loop() {
  x.setDir(true);
  y.setDir(true);
  for (int i = 0 ; i <= 600 ; i++) {
    x.moveTo();
    y.moveTo();
    delay(15);
  }
  x.setDir(false);
  y.setDir(false);
  for (int i = 0 ; i <= 600 ; i++) {
    x.moveTo();
    y.moveTo();
    delay(15);
  }

}
