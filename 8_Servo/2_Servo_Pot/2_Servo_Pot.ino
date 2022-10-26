/*
  Servo example-- Knob
  Control position of RC servo motor with Arduino and potentiometer
  Connect servo control wire to pin 9.
  Connect potentiometer middle pin to Anolog A0.
  Uses Arduino Servo library:
  https://www.arduino.cc/en/Reference/Servo
  Minimally modified from
  https://www.arduino.cc/en/Tutorial/Knob
  in the public domain
*/

#include <Servo.h>

const int potPin = 0;  // include Arduino Servo library
const int servoPin = 9;  // create servoPin variable, assign 9

int reading = 0; //variable to track potentiometer reading
int angle = 0; // variable to track motor angle between 0-180 degrees

Servo servo; // create Servo object

void setup() {
  servo.attach(servoPin);  //attach servo variable to control pin
}

void loop() {
  reading = analogRead(potPin);     // reads pot 0 to 1023
  angle = reading / 6;              // reduces pot value to 0 to 180-ish to match servo range
  servo.write(angle);    //writes to servo
}
