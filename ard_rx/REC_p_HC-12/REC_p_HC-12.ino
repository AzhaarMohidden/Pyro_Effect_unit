/*
  Example for receiving
  
  https://github.com/sui77/rc-switch/
  
  If you want to visualize a telegram copy the raw data and 
  paste it into http://test.sui.li/oszi/
*/

//int val = 0;
byte incommingByte;
#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);
unsigned long t = 0;
unsigned long t1;
int st;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  selx(49);
  delay(250);
  selx(52);
  delay(250);
  selx(55);
  delay(250);
  selx(58);
  delay(250);
}

void selx(int var){
  switch (var){
    case 3:
      Serial.println("OPEN");
      break;
    case 4:
      Serial.println("TEST");
      break;
    case 49:
      FL_ON();
      break;
    case 50:
      FL_OFF();
      break;
    case 51:
      FL_FIRE();
      break;  
    case 52:
      FR_ON();
      break;
    case 53:
      FR_OFF();   
      break;
    case 54:
      FR_FIRE();   
      break;
    case 55:
      RL_ON();   
      break;
    case 56:
      RL_OFF();   
      break;
    case 57:
      RL_FIRE();   
      break;
    case 58:
      RR_ON();   
      break;
    case 59:
      RR_OFF();   
      break;
    case 60:
      RR_FIRE();   
      break;
//      case 54:
////        mySwitch.send(5007, 24);
//        delay(1000);
//        break;
//      case 55:
////        mySwitch.send(5008, 24);
//        delay(1000);
//        break;
//      case 56:
////        mySwitch.send(5009, 24);
//        delay(1000);
//        break;
//      case 57:
////        mySwitch.send(5010, 24);
//        delay(1000);
//        break;
//      case 58:
////        mySwitch.send(5011, 24);
//        delay(1000);
//        break;
//      case 59:
////        mySwitch.send(5012, 24);
//        delay(1000);
//        break;
//      case 60:
////        mySwitch.send(5013, 24);
//        delay(1000);
//        break;
      }
    
    }
void FL_ON(){
  Serial.println("FL_ON");
  digitalWrite(4, HIGH);
  }
void FL_OFF(){
  Serial.println("FL_OFF");
  digitalWrite(4, LOW);
  }
void FL_FIRE(){
  Serial.println("FL_FIRE");
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  }
void FR_ON(){
  Serial.println("FR_ON");
  digitalWrite(5, HIGH);
  }
void FR_OFF(){
  Serial.println("FR_OFF");
  digitalWrite(5, LOW);
  }
void FR_FIRE(){
  Serial.println("FR_FIRE");
//  digitalWrite(8, LOW);
  }
void RL_ON(){
    Serial.println("RL_ON");
    digitalWrite(6, HIGH);
    }
void RL_OFF(){
    Serial.println("RL_OFF");
    digitalWrite(6, LOW);
    }
void RL_FIRE(){
    Serial.println("RL_FIRE");
  //  digitalWrite(8, LOW);
    }
void RR_ON(){
     Serial.println("RR_ON");
     digitalWrite(7, HIGH);
     }
void RR_OFF(){
     Serial.println("RR_OFF");
     digitalWrite(7, LOW);
     }
void RR_FIRE(){
     Serial.println("RR_FIRE");
    //  digitalWrite(8, LOW);
     }

  
void analog_read(){
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  int voltage = sensorValue;
  // print out the value you read:
//  Serial.println(voltage);
  if (sensorValue >=300){
    FL_FIRE();
    delay(5000);
    }
  }

  

void loop() {

  st = digitalRead(9);
  t1 = millis();
  analog_read();
  
  if (mySerial.available()) {
    incommingByte = mySerial.read();
    if (incommingByte != 10){
      incommingByte = incommingByte - 48;
      Serial.println(incommingByte);
      }
    
    selx(incommingByte); //wwwwwwwwwwww
    
//    if(incommingByte == 4){
//      Serial.println("TEST");
//      }
//    else if(incommingByte == 3){
//      Serial.println("Open");
//      }
//    else if(incommingByte == 49){
//      Serial.println("ON_FL");
//      FL_ON();
//      }
//     else if(incommingByte == 50){
//      Serial.println("OFF_FL");
//      FL_OFF();
//      }
//     else if(incommingByte == 51){
//      Serial.println("FIRE_FL");
//      }

      mySerial.write(incommingByte);    //wwwwwwwwwww
  }
  if (st != 0){
    int f = t - t1;     
    if(f > 5000 | t == 0 ){
      if(!mySerial.available()){
      t=t1;
      delay(50);
      mySerial.write(60); 
      }
      }
    
    }
}
