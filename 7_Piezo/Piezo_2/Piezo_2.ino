/*
  /*
  PIEZO PITCH FOLLOWER
  Example using tone() and anolog input to change pitch.
  Create circuit with piezo connected to digital pin 2 and ground wire to ground.
  Create circuit with one side of LDR connected to 5V.
  Other side of LDR connected to analog pin A0 and 10k pull-down resistor to ground.
  Arguments for tone= pin #, frequency in Hz, and duration of the tone in milliseconds:
  tone (pin, frequency, duration)
  Recommended to use frequencies 30-5,000 Hz.
  Modified from example code in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

// Creates global variables
const int piezo = 2; // piezo pin
int sensorReading; //to track FSR input
int pitch;  // to track pitch

void setup() {
  // initialize serial communications (for debugging only):
  //Serial.begin(9600);
}

void loop() {

  sensorReading = analogRead(A0);    // read the sensor:

  //Serial.println(sensorReading);    // print the sensor reading so you know its range

  // use map() of analog input range (0-1023 from the LDR)
  // to the output pitch range (120 - 3000Hz)

  pitch = map(sensorReading, 0, 1023, 120, 3000);

  tone(piezo, pitch, 10);  // plays pitch
  delay(1);        // delay in between reads for stability
}
