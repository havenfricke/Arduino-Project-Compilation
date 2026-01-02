#define ENABLE 5
#define DIRA 3
#define DIRB 4
#include "Stepper.h"
#include "IRremote.h"
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
int receiver = 12; // IR port
Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    // create instance of 'irrecv'
decode_results results;     // create instance of 'decode_results'
int currentMotor = 0; // current motor being controlled



void setup() {
  //---set pin direction
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR code: ");
    Serial.println(results.value, HEX);
    Serial.println(currentMotor);
    
    switch (results.value) {
      case 0xFF6897: // if 0 is pressed on remote
        currentMotor = 0;
        break;
      case 0xFF30CF: // if 1 is pressed on remote
        currentMotor = 1;
        break;
    }
    irrecv.resume(); // Prepare to receive the next value
  }

  if (currentMotor == 0) {
    switch (results.value) {
       case 0xFFA857: // VOL+ button pressed
        small_stepper.setSpeed(500); //Max seems to be 500
        Steps2Take  =  2048;  // Rotate CW
        small_stepper.step(Steps2Take);
        delay(2000); 
        break;

      case 0xFF629D: // VOL- button pressed
        small_stepper.setSpeed(500);
        Steps2Take  =  -2048;  // Rotate CCW
        small_stepper.step(Steps2Take);
        delay(2000); 
        break;
    }
  } else if (currentMotor == 1) {
    switch(results.value)
    {
      case 0xFFA857: // VOL+ button pressed
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,HIGH); 
      digitalWrite(DIRB,LOW);
      delay(500);
      break;
      case 0xFF629D: // VOL- button pressed
      digitalWrite(ENABLE,HIGH);
      digitalWrite(DIRA,LOW); 
      digitalWrite(DIRB,HIGH);
      delay(500);
      break;
    }
  }

  // Reset all stepper pins to LOW
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW); 

  // Disable other motor
  digitalWrite(ENABLE, LOW);
}
