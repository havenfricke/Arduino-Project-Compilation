#include <Encoder.h>

Encoder myEnc(11, 13);

// JOYSTICK (POTENTIOMETER) PINS
int xAxisInput = A0;
int yAxisInput = A1;
int zClickInput = 2;

// JPYSTICK VALUE TRACKING
int xAxisValue;
int yAxisValue;
int zClickValue;

//ROTARY ENCODER PINS
int rotEncClickInput = 12;
int rotEncInputA = 11;
int rotEncInputB = 13;

//ROTARY ENCODER VALUE TRACKING
int aStateValue;
int bStateValue;
int cStateValue;
int limiter;


void setup() {
  Serial.begin(9600);

  // JOYSTICK (POTENTIOMETER)
  pinMode(xAxisInput, INPUT);
  pinMode(yAxisInput, INPUT);
  pinMode(zClickInput, INPUT);

  // WAKE THE DIGITAL INPUT UP
  digitalWrite(zClickInput, HIGH);

  // ROTARY ENCODER
  pinMode(rotEncInputA, INPUT);
  pinMode(rotEncInputB, INPUT);
  pinMode(rotEncClickInput, INPUT);
}

void loop() {
//JOYTSTICK (POTENTIOMER)
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


  //ROTARY ENCODER
  aStateValue = digitalRead(rotEncInputA);
  bStateValue = digitalRead(rotEncInputB);
  cStateValue = digitalRead(rotEncClickInput);
  

  if(!aStateValue)
  {
    Serial.println("Move right");
  }
  else if (!bStateValue)
  {
    Serial.println("Move Left");
  }

  delay(200);
}
