/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
int detect_upper_limit = 750;
int detect_lower_limit = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(2, OUTPUT);//FL
  pinMode(3, OUTPUT);//FR
  pinMode(4, OUTPUT);//RL
  pinMode(5, OUTPUT);//RR
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int FL= analogRead(A0);
  int FR= analogRead(A1);
  int RL= analogRead(A2);
  int RR= analogRead(A3);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.print(FL);
  Serial.print(" : ");
  Serial.print(FR);
  Serial.print(" : ");
  Serial.print(RL);
  Serial.print(" : ");
  Serial.print(RR);
  Serial.println(" : ");
  
  
  if(FL<=detect_upper_limit && FL>=detect_lower_limit){
    digitalWrite(2, HIGH);
    Serial.print("Connected: ");
    }
  else{
    digitalWrite(2, LOW);
    Serial.print("Not Connected: ");
    }
    
  if(FR<=detect_upper_limit && FR>=detect_lower_limit){
    digitalWrite(3, HIGH);
    Serial.print("Connected: ");
    }
  else{
    digitalWrite(3, LOW);
    Serial.print("Not Connected: ");
    }
    
  if(RL<=detect_upper_limit && RL>=detect_lower_limit){
    digitalWrite(4, HIGH);
    Serial.print("Connected: ");
    }
  else{
    digitalWrite(4, LOW);
    Serial.print("Not Connected: ");
    }
    
  if(RR<=detect_upper_limit && RR>=detect_lower_limit){
    digitalWrite(5, HIGH);
    Serial.println("Connected: ");
    }
  else{
    digitalWrite(5, LOW);
    Serial.println("Not Connected: ");
    }

}
