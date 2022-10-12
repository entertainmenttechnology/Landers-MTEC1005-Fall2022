/*
  ANALOG READ
  Example using analogRead(pin) to read an analog sensor.
  Create LED circuit with LED connected to digital PWM pin 11.
  Connect potentiometer center pin to analog pin A0, one side to GND, and other side powered with 5V.
  OR connect photocell pin to analog pin A0 and other side with 10K pull-down resistor to ground
  Uncomment for serial monitor functionality.
*/

const int sensor = A0;  // creates fixed variable called sensor and assigns value A0
const int LED = 11; // creates fixed variable called LED and assigns value of 11
int value = 0;

// setup function runs once at start up
void setup() {
  pinMode(LED, OUTPUT);    // initialize pin as an output.
  // note: no need to initialize pinMode for analog pins as they can only be inputs

  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
}

// loop function runs infinitely
void loop() {
  value = analogRead (sensor); //Reads sensor pin and assigns to value
  delay (10);  //Small delay
  value = value/4;  //Dividing value by 4 reduces range to max 255
  analogWrite (LED, value); //Writes to LED
  //Serial.println(value); //Prints to serial monitor
}
