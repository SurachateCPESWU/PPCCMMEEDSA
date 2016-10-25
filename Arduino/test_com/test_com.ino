String incomingByte;   // for incoming serial data

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}


void loop() {

  String bytes;
  bytes = Serial.readString();
  if (bytes.indexOf("G1") >= 0) {
    int j = 0;
    int cmd_l = 0;
    String cmd[j];
    for (int i = 0 ; i < bytes.length(); i++) {
      if (bytes[i] != ' ') {
        cmd[j][cmd_l] = bytes[i];
        cmd_l++;
      } else {
        j++;
        String cmd[j];
        cmd_l = 0;
      }
    }
    
    for (int k = 0; k != j; k++) {
      Serial.println(cmd[k]);
    }
  }
  delay(100);
}
