const int buttonPin = 2;   // defines pin names and functions
const int fountainRelay = 9;
const int waterSensorPin = 0;
void setup(){    // sets outputs and inputs
 Serial.println("Starting");
 pinMode(fountainRelay, OUTPUT);
 pinMode(buttonPin, INPUT);
 pinMode(A0, OUTPUT);
 pinMode(6, OUTPUT);
 Serial.begin(9600);
 }
 int fountainOn = false;  // identifies the "fountainOn" variable
void loop(){
 //Serial.println("StartingLoop");
 int waterSensorValue = readSensor(waterSensorPin); //reads the water level sensor
 //Serial.println("donereadingSensor");
 int buttonState = digitalRead(buttonPin);  //toggles a light when button is pressed
  if (buttonState == HIGH) {
    if (fountainOn ==false) {
      fountainOn = true;
      digitalWrite(fountainRelay, HIGH);
      delay(1000);
    }
    else {
      fountainOn = false;
      digitalWrite(fountainRelay, LOW);
      delay(1000);
    }
  }
        if(waterSensorValue < 1000) {
    digitalWrite(fountainRelay, LOW);
    fountainOn = false;
    digitalWrite(6, LOW);}
    else {
    digitalWrite(6, HIGH);}
   Serial.println(waterSensorValue);
}
int readSensor( int analogPin ) {
 // Serial.println("Reading Sensor");
  digitalWrite( A1 + analogPin, HIGH );
  delay( 1 ); // 1 millisecond
 // Serial.println("sensorOn");
  int value = analogRead( A1 );
 // Serial.println("read sensor value");
  digitalWrite( A1 + analogPin, LOW );
  //Serial.println(value);
  return value;
}

//remove all other "//"s to enable debug mode//
