// Please ignore the commented out lines that do nothing, I am still working a lot on this file.

float RT = 10000;// the rated potentiometer value 10k
float R;// the unknown resistance value 
float R2;// the unknown resistance value R

int pot1Pin = A0; // potentiometer is connected to analog 0 pin
int pot1Value; // variable used to store the value coming from the sensor
int percent1; // variable used to store the percentage value
int clickedPercent1;
int prevClickedPercent1 = 0;

int pot2Pin = A1; // potentiometer is connected to analog 0 pin
int pot2Value; // variable used to store the value coming from the sensor
int percent2; // variable used to store the percentage value
int clickedPercent2;
int prevClickedPercent2 = 0;

int prevPot1Val = 0;
int prevPot2Val = 0;

int throttleClicks = 7; // define the amount of position a train's throttle or combined throttle/brake lever has
// The TGV Euroduplex for example needs 17 (8 in each direction for throttle + 0 throttle)
int brakeClicks = 5; // a bit more complex but similar to the 'throttleClicks'.
// For the TGV Euroduplex it is different then most locomotives as it acts as an apply or release and not a specific amount.

void setup() {
Serial.begin(9600); // initialize the serial communication
}
void loop() {


// ---Pot 1---
pot1Value = analogRead(pot1Pin); // get a reading from the potentiometer, assign the name potValue
percent1 = map(pot1Value, 0, 1020, 0, 100); // convert reading to a percentage
clickedPercent1 = map(pot1Value, 0, 1020, 0, throttleClicks);

if (clickedPercent1 < prevClickedPercent1) {
  
  Serial.println("Forward1:");
//  Serial.println(clickedPercent1); // debug info only
//  Serial.println(prevClickedPercent1); // debug info only

  prevClickedPercent1 = clickedPercent1;
  delay(1);
} else if (clickedPercent1 > prevClickedPercent1) {
  Serial.println("Back1:");
//  Serial.println(clickedPercent1); // debug info only
//  Serial.println(prevClickedPercent1); // debug info only

  prevClickedPercent1 = clickedPercent1;
  delay(1);
} else {

  prevClickedPercent1 = clickedPercent1;
  delay(1);
}

//    Serial.println("Back1:"); // ignore, temporary code
//    Serial.println("Forward1:"); // ignore, temporary code


// ---Pot 2---
pot2Value = analogRead(pot2Pin); // get a reading from the potentiometer, assign the name potValue
percent2 = map(pot2Value, 0, 1020, 0, 100) - 5; // convert reading to a percentage
clickedPercent2 = map(pot2Value, 0, 1020, 0, brakeClicks);

if (clickedPercent2 < prevClickedPercent2) {
  Serial.println("Forward2:");
//  Serial.println(clickedPercent2); // debug info only
//  Serial.println(prevClickedPercent2); // debug info only

  prevClickedPercent2 = clickedPercent2;
  delay(1);
} else if (clickedPercent2 > prevClickedPercent2) {
  Serial.println("Back2:");
//  Serial.println(clickedPercent2); // debug info only
//  Serial.println(prevClickedPercent2); // debug info only

  prevClickedPercent2 = clickedPercent2;
  delay(1);
} else {

  prevClickedPercent2 = clickedPercent2;
  delay(1);
}
delay(8);
}
