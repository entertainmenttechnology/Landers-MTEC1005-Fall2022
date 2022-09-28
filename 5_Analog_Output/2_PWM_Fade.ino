/*
  FADING WITH PWM
  Example using PWM with analogWrite(pin, value) to fade an LED.
  Uses values of 0-255 to write duty cycles between fully off and fully on states.
  Create LED circuit with LED connected to digital PWM pin 11.
*/


const int LED = 11; // creates variable called LED and assigns value of 11

// setup function runs once at start up
void setup() {
  pinMode(LED, OUTPUT);    // initialize pin as an output.
}

// loop function runs infinitely
void loop() {
  for (int i = 0 ; i <= 255; i += 5) { // for loop fades LED value from 0 to 255, incrementing by 1
    analogWrite(LED, i); //writes value of i to pin
    delay(50);  // short delay so LED effect is visible
  }

  for (int i = 255 ; i >= 0; i -= 5) { // for loop fades LED value from 255 to 0, de-incrementing by 1
    analogWrite(LED, i);
    delay(30);
  }
}
