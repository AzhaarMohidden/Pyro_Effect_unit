/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial

  
*/
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>
#define RX 2 //Connect to the TX pin of the HC-12
#define TX 3 //Connect to the RX pin of the HC-12
SoftwareSerial mySerial(RX, TX);

Adafruit_BMP085 bmp;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
   
  Serial.setTimeout(1);
  mySerial.begin(9600);
  Serial.begin(9600);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on BMp
  int sensorValue = (bmp.readPressure()- 100000)/200;
  // print out the value you read:
  
  mySerial.write(sensorValue);
  delay(150);        // delay in between reads for stability
}
