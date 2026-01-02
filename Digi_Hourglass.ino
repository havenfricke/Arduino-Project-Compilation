const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 1000;

void setup() {
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  // Update LEDs at a defined interval
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    // Turn on the current LED and increment the led index
    digitalWrite(led, HIGH);
    led++;
    //if (led == 7) { // Changed from == to > to reset correctly
    //  led = 2; // Reset to the first LED after the last one
    //}
  }

  // Read the state of the switch
  switchState = digitalRead(switchPin);

  // Check if the switch state has changed
  if (switchState != prevSwitchState) {
    // Turn off all LEDs
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }
    led = 2; // Reset led index to the first LED
    previousTime = currentTime; // Reset the timer
  }
  
  prevSwitchState = switchState; // Update previous switch state
}
