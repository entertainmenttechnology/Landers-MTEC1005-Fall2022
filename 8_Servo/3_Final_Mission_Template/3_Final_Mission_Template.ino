/*
  FINAL MISSION TEMPLATE
  Control position of RC servo motor with Arduino and potentiometer.
  Use conditions to control motor and LED.
  Connect servo control wire to pin 9.
  Connect potentiometer middle pin to Anolog A0.
  Connect LED to pin 4.
  Uses Arduino Servo library:
  https://www.arduino.cc/en/Reference/Servo
  ***MODIFY THE CONDITIONS FOR LED AND MOTOR BEHAVIOR***
*/

#include <Servo.h> // include Arduino Servo library

const int potPin = A0;  // create potPin variable, assign pin A0
const int servoPin = 9;  // create servoPin variable, assign 9
const int LED = 4;  // create LED variable, assign 4

int reading = 0; //variable to track potentiometer reading
int angle = 0; // variable to track motor angle between 0-180 degrees

Servo servo; // create Servo object

void setup() {
  servo.attach(servoPin);  //attach servo variable to control pin
  pinMode (LED, OUTPUT);  //set LED pin as output
  Serial.begin(9600);  //begin serial communication at 9600 baud rate
}

void loop() {
  reading = analogRead(potPin);     // reads pot 0 to 1023
  angle = reading / 6;              // reduces pot value to 0 to 180-ish to match servo range
  if (reading >25 && reading <= 512) { // if pot value between 25 and half

    //*******modify the LED behavior to do something else*********
    digitalWrite (LED, HIGH);  // write HIGH voltage to LED pin
    delay (500);  // delay 1/2 a second
    digitalWrite (LED, LOW);  // write no/LOW voltage to LED pin
    delay (500);

  } else if (reading > 512 && reading <= 1023) {  // else if pot value between half and max
    //********modify the sweep's speed and range***************

    // sweep 0 to 180
    for (angle = 0; angle < 180; angle++) {
      servo.write(angle);
      delay(15);
    }
    // sweep 180 to 0
    for (angle = 180; angle > 0; angle--) {
      servo.write(angle);
      delay(15);
    }
  } else {
    digitalWrite (LED, LOW);  // write no/LOW voltage to LED pin
  }
  Serial.println(reading);  // print pot value to monitor
}
