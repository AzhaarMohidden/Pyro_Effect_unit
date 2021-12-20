#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

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
  mySwitch.enableTransmit(10);
  
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  mySwitch.send(5001, 24);
  delay(1000);  
  }
int test2(){
  
  digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
//  Serial.println("test2"); 
  mySwitch.send(5000, 24);
  delay(1000);  
  }
int sel(int var){
  switch (var){
      case 49:
        mySwitch.send(5002, 24);
        delay(1000);
        break;
      case 50:
        mySwitch.send(5003, 24);
        delay(1000);
        break;
      case 51:
        mySwitch.send(5004, 24);
        delay(1000);
        break;  
      case 52:
        mySwitch.send(5005, 24);
        delay(1000);
        for (int p = 0; p<10; p++){
          //////////////////////////
        blink_t();
        /////////////////////
        }
        break;
      case 53:
        mySwitch.send(5006, 24);
        delay(1000);
        break;
      case 54:
        mySwitch.send(5007, 24);
        delay(1000);
        break;
      case 55:
        mySwitch.send(5008, 24);
        delay(1000);
        break;
      case 56:
        mySwitch.send(5009, 24);
        delay(1000);
        break;
      case 57:
        mySwitch.send(5010, 24);
        delay(1000);
        break;
      case 58:
        mySwitch.send(5011, 24);
        delay(1000);
        break;
      case 59:
        mySwitch.send(5012, 24);
        delay(1000);
        break;
      case 60:
        mySwitch.send(5013, 24);
        delay(1000);
        break;
      }
  }
    
void setup() {
 Serial.begin(9600);
 Serial.setTimeout(1);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
}


  
void loop() {
   
  if (Serial.available()>0){
     x = Serial.read();
     if(x!=10){
      x = x -48;
      Serial.println(x);
      if (x == 3){
      test();
      }
      else if(x == 4){
        test2();
        }
      }

      sel(x);
      
//      if (x == 49){
//        mySwitch.send(5002, 24);
//        delay(1000);  
//        }
//        else if (x == 50){
//        mySwitch.send(5003, 24);
//        delay(1000);  
//        }
//        else if (x == 51){
//        mySwitch.send(5004, 24);
//        delay(1000);  
//        }

  

     
    }

 //while (!Serial.available());
// x = Serial.readString().toInt();
// Serial.println(x);

}
