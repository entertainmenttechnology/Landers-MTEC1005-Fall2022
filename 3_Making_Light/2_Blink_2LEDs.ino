/*
 * Blink 2 LEDs
 * Connect LEDs to digital pins 12 and 13.
 */

const int LED1 = 12; // create a variable called LED1 and assign its value to 12
const int LED2 = 13; // create a variable called LED2 and assign its value to 13

// put your setup code here, to run once:
void setup() {
  pinMode(LED1, OUTPUT); // initialize pins as outputs
  pinMode(LED2, OUTPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  digitalWrite(LED1, HIGH); // turn on LED1
  delay(1000);              // wait 1000 milliseconds (1 second)
  digitalWrite(LED1, LOW);  // turn off LED1
  delay(1000);              // wait 1 second
  digitalWrite(LED2, HIGH); // turn on LED2
  delay(2000);              // wait 2 seconds
  digitalWrite(LED2, LOW);  // turn off LED2
  delay(2000);              // wait 2 seconds
}

// Modify the delay values to create different timing. Re-upload code to your board.
