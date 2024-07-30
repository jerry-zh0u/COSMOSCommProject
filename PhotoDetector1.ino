
#include <SoftwareSerial.h>

SoftwareSerial mySerial = SoftwareSerial(10, 3, true);

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(300);
  // mySerial.begin(300);
  Serial.begin(9600);
}

void loop() {
  //USED FOR PLOTTING ON SERIAL PLOTTER
  // int value = digitalRead(12);
  // Serial.println(value);
  // Serial.println(-1.1);
  // Serial.println(1.1); 

  while (mySerial.available() != 0) {
    Serial.print(char(mySerial.read()));
  }
}
