String Data_rec ;   // for incoming serial data

const int stepPin_X = 10;
const int dirPin_X = 11;
const int delay_X = 5;

const int stepPin_Y = 12;
const int dirPin_Y = 13;
const int delay_Y = 5;

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  
  pinMode(stepPin_X,OUTPUT);
  pinMode(dirPin_X,OUTPUT);

  pinMode(stepPin_Y,OUTPUT);
  pinMode(dirPin_Y,OUTPUT);
  
}

void loop() {
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    Data_rec = Serial.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(Data_rec);
  }

if(Data_rec=="X+"){
  Serial.println("Do X+");
  Data_rec="";
  digitalWrite(dirPin_X,LOW);
      delay(100);
      for(int x = 0; x < 600; x++) {
        digitalWrite(stepPin_X,HIGH); 
        delay(delay_X); 
        digitalWrite(stepPin_X,LOW); 
        delay(delay_X); 
      }
}

if(Data_rec=="Y+"){
  Serial.println("Do Y+");
  Data_rec="";
    digitalWrite(dirPin_Y,LOW);
      delay(100);
      for(int x = 0; x < 173; x++) {
        digitalWrite(stepPin_Y,HIGH); 
        delay(delay_Y); 
        digitalWrite(stepPin_Y,LOW); 
        delay(delay_Y); 
      }
}

if(Data_rec=="X-"){
  Serial.println("Do X-");
  Data_rec="";
  digitalWrite(dirPin_X,HIGH);
      delay(100);
      for(int x = 0; x < 600; x++) {
        digitalWrite(stepPin_X,HIGH); 
        delay(delay_X); 
        digitalWrite(stepPin_X,LOW); 
        delay(delay_X); 
      }
}

if(Data_rec=="Y-"){
  Serial.println("Do Y-");
  Data_rec="";
    digitalWrite(dirPin_Y,HIGH);
      delay(100);
      for(int x = 0; x < 173; x++) {
        digitalWrite(stepPin_Y,HIGH); 
        delay(delay_Y); 
        digitalWrite(stepPin_Y,LOW); 
        delay(delay_Y); 
      }
}

if(Data_rec=="XY+"){
  Serial.println("Do XY+");
  Data_rec="";
    digitalWrite(dirPin_Y,LOW);
    digitalWrite(dirPin_X,LOW);
      delay(100);
      for(int x = 0; x < 50; x++) {
        digitalWrite(stepPin_Y,HIGH); 
        digitalWrite(stepPin_X,HIGH); 
        delay(delay_Y); 
        digitalWrite(stepPin_Y,LOW); 
        digitalWrite(stepPin_X,LOW); 
        delay(delay_Y); 
      }
}

  
}

