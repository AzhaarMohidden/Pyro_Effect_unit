void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int FL= analogRead(A2);
  int FR= analogRead(A3);
  int RL= analogRead(A4);
  int RR= analogRead(A5);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.print(FL);
  Serial.print(" : ");
  Serial.print(FR);
  Serial.print(" : ");
  Serial.print(RL);
  Serial.print(" : ");
  Serial.print(RR);
  Serial.println(" : ");

}
