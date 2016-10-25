// Quarter step

    const int stepPin = 10; 
    const int dirPin = 11; 
    const int delayx = 5;
     
    void setup() {
      // Sets the two pins as Outputs
      pinMode(stepPin,OUTPUT); 
      pinMode(dirPin,OUTPUT);
    }
    void loop() {
      digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
      delay(100);
      // Makes 200 pulses for making one full cycle rotation
      for(int x = 0; x < 500; x++) {
        digitalWrite(stepPin,HIGH); 
        delay(delayx); 
        digitalWrite(stepPin,LOW); 
        delay(delayx); 
      }
      delay(1000); // One second delay
      
      digitalWrite(dirPin,LOW); //Changes the rotations direction
      delay(100);
      // Makes 400 pulses for making two full cycle rotation
      for(int x = 0; x < 500; x++) {
        digitalWrite(stepPin,HIGH);
        delay(delayx);
        digitalWrite(stepPin,LOW);
        delay(delayx);
      }
      delay(1000);
    }
