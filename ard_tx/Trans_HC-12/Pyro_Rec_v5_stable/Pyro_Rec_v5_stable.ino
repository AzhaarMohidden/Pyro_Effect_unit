
#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);

int x;
int t;



int blink_t(){
  t = 2*100;
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(t);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(t);  
  }

int test(){
 // digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);   //check these delays also                    // wait for a second
  //digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  //delay(1000);  //check these delays also
  delay(100);
  Serial.println("Connected");

  }
int test2(){
  
 // digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(50);                       // wait for a second
  //digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  //delay(10); 

 // delay(10);  
  }

int p; 
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
   
  if (Serial.available()){
     x = Serial.read();
     p = x;
     if(x!=10){
      x = x -48;
      if (x == 3){
      Serial.println(x);
      test();
      
      }
      else if(x == 4){
        
        test2(); //check these delays also
        //test();
        }
//      Serial.println(p);
      delay(10);
      mySerial.write(p);
      }

      delay(10);//check if this delay causes the read issue
//      delay(100);
          
    }
    if (mySerial.available()) {
     v =  mySerial.read();
      if(v != 3 ){
        Serial.println(v);
       //Serial.println("Connected");
        
        }
      
     } 
}
