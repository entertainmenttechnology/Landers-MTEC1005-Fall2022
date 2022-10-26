/*
  Servo example-- Sweep
  Rotates motor 180 degrees and back

  Connect servo control wire to pin 9.

  Uses Arduino Servo library:
  https://www.arduino.cc/en/Reference/Servo

  Minimally modified from
  https://www.arduino.cc/en/Tutorial/Sweep
  in the public domain
*/


#include <Servo.h> // include Arduino Servo library

const int servoPin = 9;  // create servoPin variable, assign 9

Servo servo;  // create Servo object

int angle = 0;   // variable to track servo position in degrees


void setup() {
  servo.attach(servoPin); //attach servo variable to control pin
}


void loop() {
  // scan from 0 to 180 degrees
  for (angle = 0; angle < 180; angle++) {
    servo.write(angle);
    delay(15);
  }
  // now scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle--) {
    servo.write(angle);
    delay(15);
  }
}
