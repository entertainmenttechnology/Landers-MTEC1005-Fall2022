const int LED = 13;
const int LED2 = 11;
const int LED3 = 9;
const int LED4 = 6;
const int buttonPin = 2;
int buttonState = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT); 
  pinMode(LED2,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(buttonPin,INPUT);
}
buttonState = analogRead(buttonPin);
void loop() {
Serial.printline(buttonState);
delay(10);
    if(buttonState == HIGH){
      digitalWrite(LED, HIGH); 
      delay(1000);             
      digitalWrite(LED, LOW);
      delay(500);   
      digitalWrite(LED3, HIGH); 
      delay(3500);              
      digitalWrite(LED3, LOW);  
      delay(1000);              
    }else{ 
      digitalWrite(LED2, HIGH); 
       delay(500);              
      digitalWrite(LED2, LOW);  
      delay(500);  
      digitalWrite(LED4, HIGH); 
       delay(800);              
      digitalWrite(LED4, LOW);  
      delay(500);        
    }
  }
}
