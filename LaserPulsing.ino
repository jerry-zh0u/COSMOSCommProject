#define ONDELAY 5
#define OFFDELAY 2

String s;
bool read = false;
int p = 0;
int interval = 5;

void laserSend(int pulse){
  for(int i = 8; i >= 0; i--){
    if((pulse & (1 << i)) == 0){
      digitalWrite(2, LOW);
    }else{
      digitalWrite(2, HIGH);
    }
    delay(ONDELAY);
    digitalWrite(2, LOW);
    // delay(OFFDELAY);
  }
}

void sendStart(){ //SEND 111111101
  for(int i = 8; i >= 0; i--){
    if(i == 1){
      digitalWrite(2, LOW);
    }else{
      digitalWrite(2, HIGH);
    }
    delay(ONDELAY);
  }
}

void sendEnd(){  //SEND 111111111
  for(int i = 8; i >= 0; i--){
    digitalWrite(2, HIGH);
    delay(ONDELAY);
  }
}

void setup() {
  Serial.begin(300);
  // p = 0;
  
  // //LASER DIODE
  // pinMode(1, OUTPUT);
  // digitalWrite(1, LOW); 
  // delay(10000);
}

void loop() {
  Serial.write("hello world");
}
