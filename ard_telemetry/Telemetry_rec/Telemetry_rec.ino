
#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);


int v;


void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1);
 mySerial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
}


  
void loop() {
   
//
if (mySerial.available()) {
     v =  mySerial.read();
     Serial.println(v);
}

//      delay(10);//check if this delay causes the read issue
//      delay(100);
          

}
