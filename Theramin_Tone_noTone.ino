  int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  Serial.begin(9600);
  Serial.print("Calibrating Now...'");
  while (millis() < 5000) 
  {
    sensorValue = analogRead(40);

    sensorValue = analogRead(40);
    sensorHigh = max(sensorHigh, sensorValue);
    sensorLow = min(sensorLow, sensorValue);

    //PREVIOUS ASSIGNMENT STEPS BELOW

    //if (sensorValue > sensorHigh)
    //{
    //  sensorHigh = sensorValue;
    //}

    //if (sensorValue < sensorHigh)
    //{
    //  sensorLow = sensorValue;
    //}
  }
  digitalWrite(ledPin, LOW);
  Serial.print("Sensor High: ");
  Serial.print(sensorHigh);
  Serial.print(", Sensor Low: ");
  Serial.print(sensorLow);
}

void loop() {
  sensorValue = analogRead(A0);

  int toneDuration = map(sensorValue, sensorLow, sensorHigh, 100, 1000); // Map sensor value to tone duration (100ms to 1000ms)

  tone(8, 2000, toneDuration); // Play tone with variable duration
  delay(toneDuration + 200);   // Wait for the tone duration plus a short pause

  tone(8, 2200, toneDuration);
  delay(toneDuration + 200);

  // PREVIOUS ASSIGNMENT STEPS BELOW

   //int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

    //tone(8,pitch,20);

  //tone(8, 2000); 
  //delay(100);
  //noTone(8);
  //delay(1000);
  //tone(8, 2200);
  //delay(100);
  //noTone(8);
  //delay(10);
  //tone(8, 2000);
  //delay(100);
  //noTone(8);
  //delay(10);
  //tone(8, 2200);
  //delay(100);
  //noTone(8);
  //delay(10);
  //tone(8, 2000);
  //delay(100);
  //noTone(8);
  //delay(100);
  //tone(8, 2200);
  //delay(100);
  //noTone(8);
  //delay(10);
  //tone(8, 2000);
  //delay(100);
  //noTone(8);
  //delay(10);
  //tone(8, 2200);
  //delay(100);
  //noTone(8);
  //delay(10);
}
