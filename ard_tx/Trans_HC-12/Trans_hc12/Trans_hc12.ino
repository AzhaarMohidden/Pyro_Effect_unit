//// See SoftwareSerial example 
//// https://www.arduino.cc/en/tutorial/SoftwareSerialExample
//
//#include <SoftwareSerial.h>
//#define RX 2 //Connect to the TX pin of the HC-12
//#define TX 3 //Connect to the RX pin of the HC-12
//SoftwareSerial mySerial(RX, TX);
//
//byte incommingByte;
////String readBuffer="";
//void setup() {
//  Serial.begin(9600);
//  mySerial.begin(9600);
//
//}
//
//void loop() { // run over and over
//  if (mySerial.available()) {
////    Serial.write(mySerial.read());
//    incommingByte = mySerial.read();
//    if(incommingByte != 10){
//      incommingByte = incommingByte - 48;
//      Serial.println(incommingByte);
//      }
////    Serial.write(10);
//  }
////  if (Serial.available()) {
////    mySerial.write(Serial.read());
////  }
////  if(readBuffer != ""){
////    Serial.println(readBuffer);
////    if(readBuffer == "abc"){
////      Serial.println("OK");
////      }
////    readBuffer="";
////    
////    }
//    
//}

#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
