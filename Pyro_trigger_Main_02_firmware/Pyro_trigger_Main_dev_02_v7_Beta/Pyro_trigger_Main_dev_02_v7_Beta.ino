
/*

*/

//int val = 0;
byte incommingByte;
#include <SoftwareSerial.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);
unsigned long t = 0;
unsigned long t1;
unsigned long t2;
unsigned long trig;
unsigned long Trig_off;
unsigned long Trig_on;
unsigned long Trig_OFF_temp;


char Terminate[] = "+";
char Telemetry_data[50] ="";
char state[7]="";
char Start[] = "T: ";
char FL_A[8] = "";
char FR_A[8] = "";
char RL_A[8] = "";
char RR_A[8] = "";
char Send[60] = "";

int GPMG_delay = 50;
int dev_id = 1;
int other_dev_id = 0;

int Faulty_level = 100;


int st;
int trigger_signal;
int trigger_counter = 0;
int EED_counter =0;
//int buzzer_counter = 0;
bool active_device = false;

bool connection_status = false;

bool RPG7_Mode = true;

bool default_status = true;
bool general_error = false;

bool FL_ARMED = false;
bool FR_ARMED = false;
bool RL_ARMED = false;
bool RR_ARMED = false;

bool FL_ERROR = false;
bool FR_ERROR = false;
bool RL_ERROR = false;
bool RR_ERROR = false;

String Telemetry_str = "";

void all_armed(){
    Serial.println("ALL Armed");
    selx(49);
    delay(100);
    selx(52);
    delay(100);
    selx(55);
    delay(100);
    selx(58);
    delay(100);
  }

void buzzer_beep(int buzzer_counter, int buz_delay){
  for(int i = 0; i<=buzzer_counter; i++){
    digitalWrite(12, HIGH);
    delay(buz_delay);
    digitalWrite(12, LOW);
    delay(buz_delay);
    }
  }
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  delay(500);
  buzzer_beep(2, 50); // Enable before deployment
  if(default_status == true){
    all_armed();    
    }
  mySerial.write(126);// Startup Alert
  buzzer_beep(1, 100);
}


void selx(int var){
  switch (var){
    case 3:
      Serial.println("Connected");
      connection_status = true;
      break;
    case 4:
      Serial.println("TEST");
      telemetry_send();
      buzzer_beep(0, 50);
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
    case 61:
     RPG7_Mode = true;
     Serial.println("ALL_FIRE");
     fire_mode();
     break;
    case 62:
     RPG7_Mode = false;
     Serial.println("SEQ_FIRE");
     fire_mode();
     RPG7_Mode = true;
     break;
    case 65:
      Trigger_reset();
      break;
    case 18:
      mySerial.write(18);
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
void Trigger_reset(){
  trigger_counter = 0;
  mySerial.write(121); //Action successfull
  buzzer_beep(0, 50);
  
  }
void FL_ON(){
  Serial.println("FL_ON");
  digitalWrite(4, HIGH);
  buzzer_beep(0, 50);
  FL_ARMED =true;
  }
void FL_OFF(){
  Serial.println("FL_OFF");
  digitalWrite(4, LOW);
  buzzer_beep(0, 50);
  FL_ARMED = false;
  }
void FL_FIRE(){
//  RPG7_Mode = true;
    Serial.println("FL_FIRE");
    digitalWrite(8, HIGH);
    delay(2500);
    digitalWrite(8, LOW);
    buzzer_beep(0, 200);
//  fire_mode();
  }
void FR_ON(){
  Serial.println("FR_ON");
  digitalWrite(5, HIGH);
  buzzer_beep(0, 50);
  FR_ARMED = true;
  }
void FR_OFF(){
  Serial.println("FR_OFF");
  digitalWrite(5, LOW);
  buzzer_beep(2, 50);
  FR_ARMED = false;
  }
void FR_FIRE(){
//  RPG7_Mode = false;
    Serial.println("FR_FIRE");
    digitalWrite(9, HIGH);
    delay(2500);
    digitalWrite(9, LOW);
    buzzer_beep(0, 200);
//  fire_mode();
//  RPG7_Mode = true;
  }
void RL_ON(){
    Serial.println("RL_ON");
    digitalWrite(6, HIGH);
    buzzer_beep(0, 50);
    RL_ARMED = true;
    }
void RL_OFF(){
    Serial.println("RL_OFF");
    digitalWrite(6, LOW);
    buzzer_beep(0, 50);
    RL_ARMED = false;
    }
void RL_FIRE(){
    Serial.println("RL_FIRE");
  //  digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
    delay(2500);
    digitalWrite(10, LOW);
    buzzer_beep(0, 200);
    
    }
void RR_ON(){
     Serial.println("RR_ON");
     digitalWrite(7, HIGH);
     buzzer_beep(0, 50);
     RR_ARMED = true;
     }
void RR_OFF(){
     Serial.println("RR_OFF");
     digitalWrite(7, LOW);
     buzzer_beep(0, 50);
     RR_ARMED = false;
     }
void RR_FIRE(){
     Serial.println("RR_FIRE");
    //  digitalWrite(8, LOW);
     digitalWrite(11, HIGH);
     delay(2500);
     digitalWrite(11, LOW);
     buzzer_beep(0, 200);
     }
void all_fire_sim(){
  Serial.println("ALL_Fire");
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(2500);
  buzzer_beep(0, 500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(3500);
  }
void all_fire_seq(){
  Serial.println("Sequential");
  digitalWrite(8, HIGH);
  delay(GPMG_delay);
  digitalWrite(9, HIGH);
  delay(GPMG_delay);
  digitalWrite(10, HIGH);
  delay(GPMG_delay);
  digitalWrite(11, HIGH);
  delay(3500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2500);
  buzzer_beep(0, 500);
  }
void fire_mode(){
  if(RPG7_Mode == true){
    all_fire_sim();
    }
  else{
    all_fire_seq();
    }
  
  }
void Error_detect_digital(){
  st = digitalRead(9);
    if (st != 0){
    int f = t - t1;     
    if(f > 5000 | t == 0 ){
      if(!mySerial.available()){
      t=t1;
      //delay(50);  
      mySerial.write(63); 
      buzzer_beep(1, 50);
      }
      }
    }
  }
  
void analog_read(){
  trigger_signal = analogRead(A0);
  if (trigger_signal>=300 and (trigger_signal<=700)){
    Trig_on = millis();
    //Serial.print("Pulse-width:-  ");//Test line
    //Serial.println(Trig_on-Trig_off);//Test line
    if(Trig_on-Trig_off >= 100){
      if(Trig_on-Trig_off <= 210){
        mySerial.write(125); //Triggered By MEU/EED
      //fire_mode();
      all_fire_sim();
      trigger_counter = trigger_counter + 1;
      delay(3000);
      buzzer_beep(5, 100);
      trig = millis();
        }
      }
    }
   else{
    Trig_off = millis();
    }
   if(trigger_signal>=1020){
    while(trigger_signal>=1020){
    EED_counter = EED_counter + 1;
    trigger_signal = analogRead(A0);
    Serial.println(EED_counter);
    }
    Serial.println(EED_counter);
    //delay(2000);
   if(EED_counter>790){
      Serial.print("EED ON");
      }
      else if(EED_counter<590){
        EED_Explosion();
      Serial.print("Exploded: ");
      Serial.println(trigger_signal);
        }
     
    //Serial.println(EED_counter);
    //delay(1000);
    
    EED_counter = 0;
    
    }
  /* if ((trigger_signal>=150) && (trigger_signal<250) ){
    EED_Explosion();
    Serial.print("Exploded: ");
    Serial.println(trigger_signal);
   }*/
   //Serial.print("Trig: ");
   //Serial.println(trigger_signal);
   
  }
void EED_Explosion(){
  mySerial.write(110);
  all_fire_sim();
  }
void Error_detect_analog(){
  int FL_OUT = analogRead(A2);
  int FR_OUT = analogRead(A3);
  int RL_OUT = analogRead(A4);
  int RR_OUT = analogRead(A5); 
  t2 = millis();
  if(t2 - trig > 6000){
  if(FL_OUT>=80){
    FL_OFF();
    FL_ERROR = true;
    Serial.print("FL_ERROR:");
    Serial.println(FL_OUT);
    mySerial.write(120);
    }
  else if(FR_OUT>=Faulty_level){
    FR_OFF();
    FR_ERROR = true;
    Serial.print("FR_ERROR:");
    Serial.println(FR_OUT);
    mySerial.write(120);
    }
  else if(RL_OUT>=Faulty_level){
    RL_OFF();
    RL_ERROR = true;
    Serial.print("RL_ERROR:");
    Serial.println(RL_OUT);
    mySerial.write(120);
    }
  else if(RR_OUT>=Faulty_level){
    RR_OFF();
    RR_ERROR = true;
    Serial.print("RR_ERROR:");
    Serial.println(RR_OUT);
    mySerial.write(120);
    }
    }
  }
  
void boolean_char(bool bool_status){
  if(bool_status == true){
    strcpy(state, "HIGH");
    }
  else{
    strcpy(state, "LOW");
    }
  }
  
void telemetry_send(){
  strcpy(FL_A, "");
  strcpy(FR_A, "");
  strcpy(RL_A, "");
  strcpy(RR_A, "");
  strcpy(state, "");
  strcpy(Send, "");
  strcpy(Telemetry_data,"");
  
  
  boolean_char(FL_ARMED);
  strcpy(FL_A, state);
  boolean_char(FR_ARMED);
  strcpy(FR_A, state);
  boolean_char(RL_ARMED);
  strcpy(RL_A, state);
  boolean_char(RR_ARMED);
  strcpy(RR_A, state);
//  char Telemetry_data[] = "Tele-rick-metry Data";

  
  strcpy(Telemetry_data,FL_A);
  strcat(Telemetry_data," : ");
  strcat(Telemetry_data,FR_A);
  strcat(Telemetry_data," : "); 
  strcat(Telemetry_data,RL_A);
  strcat(Telemetry_data," : ");
  strcat(Telemetry_data,RR_A);
  strcat(Telemetry_data," : ");

 
 strcpy(Send, Start);
 strcat(Send, Telemetry_data);
 strcat(Send, Terminate);
//   String d = String("T:") + String("Telemetry Data") + String("+");
////  char s[] = String("T:") + String("Telemetry Data") + String("+");
//  char s[d.length() + 1];
//  strcpy(s, d.c_str());
  
//  mySerial.write("T: Telemetry Data+");
   mySerial.write(Send);
   Serial.println("Sent");
   Serial.println(Send);

  }

void loop() {
  t1 = millis();
  if (trigger_counter<=2){
    analog_read();
    }
  if (mySerial.available()) {
    incommingByte = mySerial.read();
    if (incommingByte != 10){
      incommingByte = incommingByte - 48;
      Serial.println(incommingByte);
      if(incommingByte == dev_id){
        active_device = true;
        }
       else if(incommingByte == other_dev_id){
        active_device = false;
        }
      }
      
      if(active_device == true){
        if(incommingByte != 18 and incommingByte != 17 ){
          mySerial.write(incommingByte);  
        }  
      selx(incommingByte);
      }
      
  }
  
  
//  Error_detect_digital();
  //Error_detect_analog();
  
  

}
