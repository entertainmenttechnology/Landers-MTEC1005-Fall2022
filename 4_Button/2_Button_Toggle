/*
  Button - Toggle

  Each time the button is pressed, the LED toggles between LOW and HIGH.

  The circuit:
  - LED attached from pin 13 to ground with 330 or 220 resistor.
  - pushbutton attached from pin 2 to +5V
  - 10 kilohm resistor attached from pin 2 to ground

  Modified from Arduino example code in the public domain.
*/


// sets up constant integer variables for pins (will not change)
const int buttonPin = 2;     // creates variable called buttonPin and assigns value of 2
const int LED =  13;      // creates variable called LED and assigns value of 13

// sets up integer variables that will change over time, assigns initial values
int LEDState = LOW;         // tracks current state of LED pin
int buttonState = LOW;             // tracks current reading of button pin
int lastButtonState = LOW;   // tracks previous reading of button pin


// setup runs once at startup
void setup() {
  pinMode(buttonPin, INPUT);  // initialize pushbutton pin as an input.
  pinMode(LED, OUTPUT);  // initialize LED pin as an output
}

// loop runs infinitely
void loop() {
  buttonState = digitalRead(buttonPin); // read value of buttonPin and store it in buttonState
  delay (10); //small delay for physical button debouncing, to increase accuracy

  //conditional statement
  if (buttonState == HIGH && lastButtonState == LOW) { //check for button transition
    LEDState = !LEDState; //assign opposite value of LEDState to new LEDState
  } else { //otherwise
    //do nothing
  }

  lastButtonState = buttonState; // assign current value of buttonState to lastButtonState

  // conditional statement for writing to LED pin
  if (LEDState == 1) { // if value of LEDState equals 1
    digitalWrite (LED, HIGH);  //send voltage to LED pin
  } else { //otherwise
    digitalWrite (LED, LOW);  //turn off voltage to LED pin
  }
}
