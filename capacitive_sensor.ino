#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

 //int threshold = 100;
 //const int ledPin = 12;

 int lowThresh = 100;
 int midThresh = 300;
 int hiThresh = 400;

 const int blueLEDPin = 10;
 const int greenLEDPin = 9; 
 const int redLEDPin = 8; 

 const int buzzerPin = 7;

void setup() {
    Serial.begin(9600);
    pinMode(redLEDPin, OUTPUT);
    pinMode(greenLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.println(sensorValue);

   if(sensorValue > lowThresh && sensorValue < midThresh) 
   {
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, LOW);

      digitalWrite(buzzerPin, LOW);
   }
   else if (sensorValue > lowThresh && sensorValue > midThresh && sensorValue < hiThresh) 
   {
      digitalWrite(blueLEDPin, HIGH);
      digitalWrite(redLEDPin, LOW);
      digitalWrite(greenLEDPin, HIGH);

      digitalWrite(buzzerPin, LOW);
   }
   else if (sensorValue > hiThresh)
   {
      digitalWrite(blueLEDPin, LOW);
      digitalWrite(redLEDPin, HIGH);
      digitalWrite(greenLEDPin, HIGH);

      digitalWrite(buzzerPin, HIGH);
   }
  delay(10); 
}
