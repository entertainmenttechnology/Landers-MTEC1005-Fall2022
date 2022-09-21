/*
 * Blink
 * Blink an LED on for one second, then off for one second, in an infinite loop.
 * Connect LED to digital pin 13.
 * Modified from Arduino example code:
 * http://www.arduino.cc/en/Tutorial/Blink
 */

// Use comments to make your code more readable.
// Comments get ignored when the program runs. 

// Pay attention to punctuation, spelling and capitalization.
// But spacing     does not matter.

const int LED = 13; // created a variable called LED and assigned it the value of 13

  // put your setup code here, to run once:
void setup() {
  pinMode(LED, OUTPUT);  // initialize pin as an output
}

  // put your main code here, to run repeatedly:
void loop() {
  digitalWrite(LED, HIGH); // send voltage to LED pin
  delay(1000);             // delays 1000 milliseconds (1 second)
  digitalWrite(LED, LOW);  // stop sending voltage to LED pin
  delay(1000);             // delays 1 second before beginning the loop again
}


// Modify the value of the delay functions. Re-upload code to your board.
