#include <SoftwareSerial.h>

#define DELAYFACTOR 50
#define SPACEDELAY 20

SoftwareSerial mySerial[2] = {SoftwareSerial(2, 3), SoftwareSerial(6, 7)};

int p = 0;
bool read[3] = {false, false, false}; 

String s[3];

void setup() {
  Serial.begin(9600); 
  mySerial[0].begin(300);
  mySerial[1].begin(300);

  p = 0;
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
      p = 0;
    }
  }
  for(int i = 0; i < 3; i++){
    if(i == 1){
      while(p < s[1].length()){
        if(s[1].charAt(p) == '\n'){
          digitalWrite(5, LOW);
        }else{
          digitalWrite(5, HIGH);
          delay((s[1].charAt(p) - 32 + 1) * DELAYFACTOR);
        }
        digitalWrite(5, LOW);
        delay(500);
        p++;
      }
    }else{
      if(i == 2){
        realIDX = 1;
      }

      mySerial[realIDX].print(" ");
      for(int j = 0; j < s[realIDX].length(); j+=5){
        mySerial[realIDX].print(s[i].substring(j, j + 5));
      }
    }
    
    Serial.print("Word "); Serial.print(i); Serial.println(": ");
    Serial.println(s[i]);
    read[i] = false;
  }
  p = 0;
}
