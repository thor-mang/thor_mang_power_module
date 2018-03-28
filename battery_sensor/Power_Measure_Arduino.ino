const int analogInPin_0 = A0; 
const int analogInPin_1 = A1;
const int analogInPin_2 = A2;
const int analogInPin_3 = A3;
const int analogInPin_4 = A4;
const int analogInPin_5 = A5;

int val_0 = 0;  
int val_1 = 0;
int val_2 = 0;
int val_3 = 0;
int val_4 = 0;
int val_5 = 0;      

void printSensor(String sensorName, int value){
  Serial.print(sensorName);
  Serial.print(value);
  Serial.print("\n");
}
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  val_0 = analogRead(analogInPin_0);
  val_1 = analogRead(analogInPin_1);
  val_2 = analogRead(analogInPin_2);
  val_3 = analogRead(analogInPin_3);
  val_4 = analogRead(analogInPin_4);
  val_5 = analogRead(analogInPin_5);

  // print the results to the Serial Monitor:
  printSensor("val 0: ",val_0);
  printSensor("val 1: ",val_1);
  printSensor("val 2: ",val_2);
  printSensor("val 3: ",val_3);
  printSensor("val 4: ",val_4);
  printSensor("val 5: ",val_5);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(1000);
}
