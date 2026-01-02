int xAxisInput = A0;
int yAxisInput = A1;
int zClickInput = 2;

int xAxisValue;
int yAxisValue;
int zClickValue;

void setup() {
  Serial.begin(9600);
  pinMode(xAxisInput, INPUT);
  pinMode(yAxisInput, INPUT);
  pinMode(zClickInput, INPUT);

  // WAKE THE DIGITAL INPUT UP
  digitalWrite(zClickInput, HIGH);
}

void loop() {
  // READ X AND Y POTENTIOMETER VALUES
  xAxisValue = analogRead(xAxisInput);
  yAxisValue = analogRead(yAxisInput);

  // READ DIGITAL INPUT Z-CLICK
  zClickValue = digitalRead(zClickInput);

  // FLIP CLICK VALUES AROUND SINCE WE HAD TO WAKE IT UP
  switch(zClickValue)
  {
    case 1:
      zClickValue = 0;
      break;
    case 0:
      zClickValue = 1;
      break;
  }

  //DEBUG - Used by Unity to get input
  Serial.println("x" + String(xAxisValue));
  Serial.println("y" + String(yAxisValue));
  Serial.println("z" + String(zClickValue));
  
  delay(50);
}
