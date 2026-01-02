const int sensorPin = A0; //
const float baselineTemp = 71.56;

void setup() 
{
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() 
{
  int sensorVal = analogRead(sensorPin);

  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C:");
  float temperature = (voltage - .5) * 5.532;
  float tempCel = temperature;
  float tempFar = (temperature * 9/5) + 32;
  Serial.print(tempCel);
  Serial.print(", degrees F:");
  Serial.print(tempFar);
  
  
  
  Serial.print("\n");
  
  if(tempFar < baselineTemp)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(tempFar >= baselineTemp + 0.2 && tempFar < baselineTemp + 0.3)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (tempFar >= baselineTemp + 0.3 && tempFar < baselineTemp + 0.4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (tempFar >= baselineTemp + 0.5)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
