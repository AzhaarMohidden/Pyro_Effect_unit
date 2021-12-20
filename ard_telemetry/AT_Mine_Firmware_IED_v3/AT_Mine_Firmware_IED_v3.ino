
#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
SoftwareSerial mySerial(RX, TX);


int v;
int act = 0;


void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1);
 mySerial.begin(9600);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(8, OUTPUT);
// pinMode(9, OUTPUT);
 myservo.attach(9); 
}


  
void loop() {
   
//
//if (mySerial.available()) {
//     v =  mySerial.read();
//     Serial.println(v);
//     
//}
v =  mySerial.read();
//     Serial.println(v);
     
     if(v>=80&& act != 1){
      myservo.write(180);              // tell servo to go to position in variable 'pos'
      delay(1500);
//      Serial.println("actt");
      myservo.write(90);
      act = 1;
      }
      else{
        act = 0;
        
        }

//      delay(10);//check if this delay causes the read issue
//      delay(100);
          

}
