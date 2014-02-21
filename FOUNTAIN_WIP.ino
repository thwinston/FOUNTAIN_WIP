const int buttonPin = 2;
const int ledPin = 9;
void setup(){
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT);
 }
 int fountainOn = false;
void loop(){
 int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (fountainOn ==false) {
      fountainOn = true;
      digitalWrite(ledPin, HIGH);
      delay(1000);
    }
    else {
      fountainOn = false;
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
  }
}


