/*
  HC-SR501 PIRMotion Sensor Demo
  Motion sensor with delay
  Set Sensor for 3-second trigger
  Utilizing a Corsair A120 Computer Fan (12V DC, 0.19A)

*/

// Define Pins for LED
int detectedLED = 13;
int readyLED = 12;
int waitLED = 11;

// Define Pins for DC Fan
// will utilize digital pin 9
int dcFan = 9;

// Input for PIR Sensor
int pirPin = 7;

// Variable for Motion Detected default as 0
int motionDetected = 0;

// Value to store PIR Value into empty variable
int pirValue;

// Input for Push Button
int buttonPin = 2;

// button variable
int buttonState = 0;

void setup() {
  // Setting up the LEDs & DC Fan as Outputs
  pinMode(detectedLED, OUTPUT);
  pinMode(readyLED, OUTPUT);
  pinMode(waitLED, OUTPUT);
  pinMode(dcFan, OUTPUT);

  // Setting up the PIR Sensor as the Input, 1 or 0
  pinMode(pirPin, INPUT);

  // Setting up push button as an input
  pinMode(buttonPin, INPUT);
  
  // Writing the outputs
  digitalWrite(detectedLED, LOW);
  digitalWrite(dcFan, LOW);
  digitalWrite(readyLED, LOW);
  digitalWrite(waitLED, HIGH);
  // Initial 1 Minute delay to stabilize/acclimatize sensor
  delay(60000); 
  digitalWrite(readyLED, HIGH);
  digitalWrite(waitLED, LOW);

}

void loop() {
  // Set up a variable for the motion sensor value
  pirValue = digitalRead(pirPin);
  //  detectedPin

  buttonState = digitalRead(buttonPin);

  // booleans for motion detection
  if (pirValue == 1){
    digitalWrite(detectedLED, HIGH);
    digitalWrite(readyLED,LOW);
    //    will trigger DC fan after 5min delay
    delay(300000);
    digitalWrite(dcFan, HIGH);
    motionDetected = 1;
 
    //  run DC fan for 10 mins with 45CFM fan 
    delay(600000);
  }
  else {
      digitalWrite(detectedLED, LOW);
  };

  // Sensor Reset Delay, 6 seconds
  if (motionDetected == 1) {
    digitalWrite(detectedLED, LOW);
    digitalWrite(dcFan, LOW);
    digitalWrite(readyLED, LOW);
    digitalWrite(waitLED, HIGH);
    delay(6000);
    digitalWrite(readyLED, HIGH);
    digitalWrite(waitLED, LOW);
    motionDetected = 0;
    
  };

  if(motionDetected == 0){
    // Add pushbutton code here - pushing button will run fan for 5 mins(300000ms)
    if (buttonState == LOW){
      digitalWrite(readyLED, LOW);
      digitalWrite(detectedLED, HIGH);
      digitalWrite(dcFan, HIGH);
      delay(300000);
      digitalWrite(dcFan, LOW);
      buttonState = HIGH;
    }
    else if(buttonState == HIGH){
      digitalWrite(readyLED, HIGH);
      digitalWrite(detectedLED, LOW);
      buttonState = LOW;
    }
    else{
      digitalWrite(detectedLED, LOW);
      
    }
  };



}
