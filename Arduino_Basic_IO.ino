int switchState = 0; 		        //Initialize switchState Integer/Boolean to False (0) (True = 1)

void setup() {
                                // set pin modes w/ parameters --> pinMode(pin number on motherboard, IO state)
  pinMode(3, OUTPUT);           // write
  pinMode(4, OUTPUT);           // write
  pinMode(5, OUTPUT);           // write
  pinMode(2, INPUT);            // read
  Serial.begin(9600);           // Begin/Initialize serial port monitor @ 9600 baud rate
}

void loop() {
  switchState = digitalRead(2); // Assign switchState during loop to INPUT (pin 2 / read) value

  if (switchState == LOW)       // Button NOT pressed (0)
  {
    digitalWrite(3, HIGH);      // green LED on, params --> digitalWrite(pin number on motherboard, IO state)
    digitalWrite(4, LOW);       // red LED off
    digitalWrite(5, LOW);       // red LED off
  } 
  else                          // Button IS pressed (1)
  {
    digitalWrite(3, LOW);       // green LED off

                                // begin alternation

    digitalWrite(4, LOW);       // red LED off
    digitalWrite(5, HIGH);      // red LED on

    delay(100);                 // 100 ms to alternate

    digitalWrite(4, HIGH);      // red LED on
    digitalWrite(5, LOW);       // red LED off

    delay(100);                 // 100 ms to return
  }

  Serial.println(switchState);  // Serial port monitor print value of swtichState INPUT (pin 2 / read) after loop end
}                               // Loop return