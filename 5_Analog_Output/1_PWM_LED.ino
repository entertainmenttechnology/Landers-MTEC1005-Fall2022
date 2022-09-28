/*
  PWM
  Example using PWM with analogWrite(pin, value) to dim an LED.
  Use values of 0-255 to write duty cycles between fully off and fully on states. 
  Create LED circuit with LED connected to digital PWM pin 11.
*/


const int LED = 11; // creates variable called LED and assigns value of 11

// setup function runs once at start up
void setup() {
  pinMode(LED, OUTPUT);    // initialize pin as an output.
}

// loop function runs infinitely
void loop() {
  analogWrite(LED, 255);   // writes duty cycle at 100%, LED fully on
  delay(1000);               // delays 1000 milliseconds (1 second)
  analogWrite(LED, 191);    // writes duty cycle at 75%, 
  delay(1000);               // delays 1000 milliseconds (1 second)
  analogWrite(LED, 127);    // writes duty cycle at 50%, LED dimmed at half
  delay(1000);               // delays 1 second
  analogWrite(LED, 64);    // writes duty cycle at 25%
  delay(1000);               // delays 1 second
  analogWrite(LED, 0);    // writes duty cycle at 0%, LED fully off
  delay(2000);               // delays 2 seconds
}


// Modify the values of analogWrite() and delay() functions. Re-upload code to your board.
