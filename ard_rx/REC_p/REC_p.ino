/*
  Example for receiving
  
  https://github.com/sui77/rc-switch/
  
  If you want to visualize a telegram copy the raw data and 
  paste it into http://test.sui.li/oszi/
*/

#include <RCSwitch.h>
int val = 0;
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}

void FL_ON(){
  digitalWrite(8, HIGH);
  }
void FL_OFF(){
  digitalWrite(8, LOW);
  }

void loop() {
  if (mySwitch.available()) {
    val = mySwitch.getReceivedValue();
    
    
    if(val==5000){
      Serial.println("TEST");
      }
    else if(val==5001){
      Serial.println("Open");
      }
    else if(val==5002){
      Serial.println("ON_FL");
      FL_ON();
      }
     else if(val==5003){
      Serial.println("OFF_FL");
      FL_OFF();
      }
     else if(val==5004){
      Serial.println("FIRE_FL");
      }
      
      Serial.println("RAW DATA:");
    output(val, mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedRawdata(),mySwitch.getReceivedProtocol());
    mySwitch.resetAvailable();
  }
}
