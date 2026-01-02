#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
int previousReply = -1; // Initialize to an invalid reply

#define randomHatStartNum 0  // starting number in hat
#define randomHatEndNum 7    // ending number in hat - end has to be larger than start  
#define numberInHat (randomHatEndNum - randomHatStartNum) + 1

int randomHat() {
    int thePick;    // this is the return variable with the random number from the pool
    int theIndex;
    static int currentNumInHat = 0;
    static int randArray[numberInHat];

    if (currentNumInHat == 0) { // hat is empty - all have been chosen - fill up array again
        for (int i = 0; i < numberInHat; i++) { // Put 1 TO numberInHat in array - starting at address 0.
            if (randomHatStartNum < randomHatEndNum) {
                randArray[i] = randomHatStartNum + i;
            }
        }
        currentNumInHat = abs(randomHatEndNum - randomHatStartNum) + 1; // reset current Number in Hat
        Serial.print(" hat is empty ");
        // if something should happen when the hat is empty do it here
    }

    theIndex = random(currentNumInHat); // choose a random index from number in hat
    thePick = randArray[theIndex];
    randArray[theIndex] = randArray[currentNumInHat - 1]; // copy the last element in the array into the the empty slot
    currentNumInHat--;    // decrement number in hat

    delay(100);
    return thePick;
}

void setup() {
    Serial.begin(9600);
    Serial.println("start ");

    lcd.begin(16, 2);
    pinMode(switchPin, INPUT);
    lcd.print("Ask the");
    lcd.setCursor(0, 1);
    lcd.print("Crystal Ball!");
}

void loop() {
    switchState = digitalRead(switchPin);
    if (switchState != prevSwitchState) {
        if (switchState == LOW) { 
            do {
                previousReply = reply; // Store the last reply
                reply = randomHat(); // Get a new random reply

                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("The ball says:");
                lcd.setCursor(0, 1);

                switch (reply) {
                    case 0:
                        lcd.print("Think about it");
                        break;
                    case 1:
                        lcd.print("Nice work");
                        break;
                    case 2:
                        lcd.print("When pigs fly");
                        break;
                    case 3:
                        lcd.print("Error");
                        break;
                    case 4:
                        lcd.print("lol, no");
                        break; 
                    case 5:
                        lcd.print("Probability low");
                        break; 
                    case 6:
                        lcd.print("Try rizz");
                        break; 
                    case 7:
                        lcd.print("Probability high");
                        break;
                }

            } while (reply == previousReply); // Repeat until we get a new reply
        }
    }
    prevSwitchState = switchState;
}
