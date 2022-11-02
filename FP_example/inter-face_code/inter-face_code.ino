/*
  INTER-FACE FINAL PROJECT EXAMPLE

  Wiring:
  LEDs to pins 5 and 11.
  Piezo to pin 2.
  Servo to pin 6.
  Potentiometer to pin A0.

  Note: selecting different PWM pins may interfere with servo library or piezo functionality.

  Interaction-- turn potentiometer for 3 states:
  1.) All off
  2.) Sad state: LEDs fade, downturned smile, lower tones
  3.) Happy state: LEDs blink, upturned smile, higher tones

  (Code from AB.)
*/

#include <Servo.h> // include Arduino Servo library
Servo servo;  // create Servo object

//Global variables
const int LEDL = 5; // left LED
const int LEDR = 11;  // right LED
const int piezo = 2;  // piezo
const int servoPin = 6;  //servo
const int sensor = A0;  // potentiometer
int value = 0; // potentiometer value
int angle = 0;   // servo position in degrees


// setup function runs once at start up
void setup() {
  pinMode(LEDL, OUTPUT);    // initialize pin as an output
  pinMode(LEDR, OUTPUT);    // initialize pin as an output
  servo.attach(servoPin); //attach servo variable to control pin
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
}

// loop function runs infinitely
void loop() {

  value = analogRead (sensor); //Reads sensor pin and assigns to value
  delay (10);  //Small delay
  value = value / 4; //Dividing value reduces range to max 255

  if (value >= 25 && value <= 127) {  // if pot position 25-127
    //LEDS
    for (int fade = 0 ; fade <= 255; fade += 5) { // for loop fades up LED value from 0 to 255, incrementing by 5
      analogWrite(LEDL, fade); //writes value to pin
      analogWrite(LEDR, fade);
      delay(10);  // short delay
    }
    for (int fade = 255 ; fade >= 0; fade -= 5) { // for loop fades LED value from 255 to 0, de-incrementing by 5
      analogWrite(LEDL, fade);
      analogWrite(LEDR, fade);
      delay(30); //short delay
    }
    //SERVO
    for (angle = 0; angle < 20; angle++) {   // sweep servo from 0 to 20 degrees
      servo.write(angle);  // write to servo pin
      delay(15);
    }
    for (angle = 20; angle > 0; angle--) {  // sweep servo from 20 to 0 degrees
      servo.write(angle);
      delay(15);
    }
    //PIEZO
    tone(piezo, 1500, 500); //send tone to piezo pin, 1500 Hz, 500 ms duration
    delay(1000);
    tone(piezo, 500, 1000);
    delay(1000);
  }

  else if (value > 127 && value <= 255) {  //pot position 127-255
    //LEDS
    analogWrite (LEDL, 0);
    analogWrite (LEDR, 0);
    delay (500);
    analogWrite (LEDL, 255);
    analogWrite (LEDR, 255);
    delay (500);
    analogWrite (LEDL, 0);
    analogWrite (LEDR, 0);
    delay (500);
    analogWrite (LEDL, 255);
    analogWrite (LEDR, 255);
    //SERVO
    for (angle = 180; angle > 145; angle--) {  // sweep from 180 to 145 degrees
      servo.write(angle);
      delay(15);
    }
    for (angle = 145; angle < 180; angle++) {   // sweep from 145 to 180 degrees
      servo.write(angle);
      delay(15);
    }
    //PIEZO
    tone(piezo, 2000, 500); //send tone to piezo pin, 2000 Hz, 500 ms duration
    delay(1000);
    tone(piezo, 2500, 1000);
    delay(1000);
  } else {  //if pot pin does not meet conditions above
    //TURN LEDS OFF
    analogWrite (LEDL, 0);
    analogWrite (LEDR, 0);
  }
  Serial.println(value); //Prints pot value to serial monitor
}
