/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int intLed = 13;


int extLed = 10;

int button = 3;



int currentVal = 1;
int lastVal = 1;
int state = 1;
int changed = 0;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(intLed, OUTPUT);     
  pinMode(extLed, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
   
  currentVal = digitalRead(button);
  if (currentVal == LOW) {
    digitalWrite(intLed, HIGH);
  }
  else {
    digitalWrite(intLed, LOW);
  }  
 
  if (currentVal != lastVal) {
    if (changed == 0) {
        state = !state;
        changed = 1;
    }
    else {
      changed = 0;
    }

    lastVal = currentVal;
  }  
  



  if (state == 1) {
    digitalWrite(extLed, LOW);
  }
  else {
    digitalWrite(extLed, HIGH);
  }
}
