#include <SoftwareSerial.h>


SoftwareSerial mySerial[3] = {SoftwareSerial(2, 3), SoftwareSerial(4, 5), SoftwareSerial(6, 7)};

int p = 0;
bool read[3] = {false, false, false}; 

String s[3];

void setup() {
  Serial.begin(9600); 
  for(int i = 0; i < 3; i ++){
    mySerial[i].begin(300);
  }
}

void loop() {
  for(int i = 0; i < 3; i++){
    Serial.print("Please input a message for Laser "); Serial.print(i); Serial.println(":");
    while(!Serial.available() && !read[i]){
      continue;
    }
    if(!read[i]){
      s[i] = Serial.readString();
      read[i] = true;
    }
  }
  for(int i = 0; i < 3; i++){
    mySerial[i].println(s[i]);
    Serial.print("Word "); Serial.print(i); Serial.println(": ");
    Serial.println(s[i]);
    read[i] = false;
  }
}
