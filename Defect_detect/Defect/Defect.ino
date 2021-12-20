/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  delay(100);
  digitalWrite(4, HIGH);
  delay(250);
  digitalWrite(7, HIGH);
  delay(250);
  digitalWrite(5, HIGH);
  delay(250);
  digitalWrite(6, HIGH);
  delay(250);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A5);
  int sensorValue2 = analogRead(A4);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A2);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  // print out the value you read:
  Serial.print(sensorValue1);
  Serial.print(" : ");
  Serial.print(sensorValue2);
  Serial.print(" : ");
  Serial.print(sensorValue3);
  Serial.print(" : ");
  Serial.println(sensorValue4);
//  delay(150);
}
