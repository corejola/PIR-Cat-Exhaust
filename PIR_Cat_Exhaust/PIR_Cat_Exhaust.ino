/*
  HC-SR501 Motion Sensor Demo
  Motion sensor with delay
  Set Sensor for 3-second trigger

  Utilizing a Corsair A120 Computer Fan
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

void setup() {
  // Setting up the LEDs & DC Fan as Outputs
  pinMode(detectedLED, OUTPUT);
  pinMode(readyLED, OUTPUT);
  pinMode(waitLED, OUTPUT);
  pinMode(dcFan, OUTPUT);

  // Setting up the PIR Sensor as the Input
  pinMode(pirPin, INPUT);

  //  Initial 1 Minute dealy to stabilize sensor
  digitalWrite(detectedLED, LOW);
  digitalWrite(dcFan, LOW);
  digitalWrite(readyLED, LOW);
  digitalWrite(waitLED, HIGH);
  delay(60000); // 1 min, time in milliseconds
  digitalWrite(readyLED, HIGH);
  digitalWrite(waitLED, LOW);

}

void loop() {
  // Set up a variable for the motion sensor value
  pirValue = digitalRead(pirPin);
//  detectedPin

  // booleans for motion detection
  if (pirValue == 1){
    digitalWrite(detectedLED, HIGH);
    //    will trigger DC fan after 30s delay
    delay(3000);
    digitalWrite(dcFan, HIGH);
    motionDetected = 1;
    //    run DC fan for 30s
    delay(30000);  
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
      
    }

    

}
