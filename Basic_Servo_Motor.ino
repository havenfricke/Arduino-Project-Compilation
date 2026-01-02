#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("PotVal: ");
  Serial.print(potVal);

  //angle = map(potVal, 0, 1023, 0, 200); map(value or variable, value from, value to, newvalue from, newvalue to) takes a range of numbers and converts to new range of numbers.
  angle = map(potVal, 1023, 0, 0, 200); //changes direction of servo motor map(potVal, 0, 1023, 200, 0) would have the same effect
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
