// Please ignore the commented out lines that do nothing, I am still working a lot on this file.

float RT = 10000;// the rated potentiometer value 10k
float R;// the unknown resistance value 
float R2;// the unknown resistance value R

int pot1Pin = A0; // potentiometer is connected to analog 0 pin
int pot1Value; // variable used to store the value coming from the sensor
int percent1; // variable used to store the percentage value
int clickedPercent1 = 0;
int prevClickedPercent1 = 0;

int pot2Pin = A1; // potentiometer is connected to analog 0 pin
int pot2Value; // variable used to store the value coming from the sensor
int percent2; // variable used to store the percentage value
int clickedPercent2; \
int prevClickedPercent2 = 0;

int prevPot1Val = 0; // potentiometer 1's previous value to detect movement
int prevPot2Val = 0; // potentiometer 2's previous value to detect movement

int throttleClicks = 17; // define the amount of position a train's throttle or combined throttle/brake lever has
// The TGV Euroduplex for example needs 17 (8 in each direction for throttle + 0 throttle)
int brakeClicks = 3; // a bit more complex but similar to the 'throttleClicks'.
// For the TGV Euroduplex it is different to most locomotives as it acts as an apply or release and not a specific amount.

void setup() {
  Serial.begin(9600); // initialize the serial communication
  for (int i = 0; i <= 5; i++) {
    Serial.println("Back1:");
    Serial.println("Back2:");
    delay(20);
  }
  clickedPercent1 = float(pot1Value) / float(100 / float(throttleClicks));
  clickedPercent2 = float(pot2Value) / float(100 / float(brakeClicks));
}
void loop() {


  // ---Potentiometer 1---
  pot1Value = analogRead(pot1Pin) / 10.1;
  pot2Value = analogRead(pot2Pin) / 10.2;
  
  prevClickedPercent1 = clickedPercent1;
  // Serial.print("Previous 1:");
  // Serial.println(prevClickedPercent1); 
  // delay(200);
  clickedPercent1 = float(pot1Value) / float(100 / float(throttleClicks));
  // Serial.print("New 1:");
  // Serial.println(clickedPercent1); 

  if(float(clickedPercent1) - float(prevClickedPercent1) > 0){
    for(int i = clickedPercent1 - prevClickedPercent1; i >= 0; i = i-1){
      //Serial.println(i);
      Serial.println("Back1:");
      delay(150);
    }
  }
  if(clickedPercent1 - prevClickedPercent1 < 0){
    for(int i = clickedPercent1 - prevClickedPercent1; i <= 0; i = i+1){
      //Serial.println(i);
      Serial.println("Forward1:");
      delay(150);
    }
  }
}
