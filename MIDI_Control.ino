#include "MIDIUSB.h"

//Using Arduino Leonardo

// Potentiometer
int potPin = A0;
int potVal = 0;

// Buttons - Inputs 2, 3, 4
int bassInput = 2;
int snareInput = 3;
int hiHatInput = 4;
int sequenceInput = 5;

int bassVal;
int snareVal;
int hiHatVal;
int sequenceVal;

//Alterations
int hatArray[] = {42,44,46};
int bassArray[] = {0, 1, 2};

// Input loudness
int bassLoudness = 0;
int snareLoudness = 0;
int hiHatLoudness = 0;
int sequenceLoudness = 0;

// Beat counter
int counter = 0;

void noteOn(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) 
{
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

void programChange(byte channel, byte program) 
{
  midiEventPacket_t programChange = {0x0C, 0xC0 | channel, program, 0};
  MidiUSB.sendMIDI(programChange);
}

void controlChange(byte channel, byte control, byte value) 
{
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void setup() 
{
  Serial.begin(115200);
  randomSeed(analogRead(A1)); // Seed the random number generator with an unconnected analog input pin (you can use A0 as well if preferred).
}

void loop() 
{
  potVal = analogRead(potPin);
  int potValMapped = map(potVal, 0, 1023, 35, 81);

  bassVal = digitalRead(bassInput);
  snareVal = digitalRead(snareInput);
  hiHatVal = digitalRead(hiHatInput);
  sequenceVal = digitalRead(sequenceVal);

  Serial.println(potValMapped);
  Serial.println(counter);

  // Reset loudness values
  bassLoudness = 0;
  snareLoudness = 0;
  hiHatLoudness = 0;

  // Trigger bass drum (channel 9, note 36)
  if (bassVal == 1 && (counter == 0 || counter == 2))
  {
    bassLoudness = 100;
  }

  if (snareVal == 1 && (counter == 1 || counter == 5))
  {
    snareLoudness = random(75, 127); 
  }

  if (sequenceVal == 1 && (counter == 2 || counter == 4))
  {
    sequenceLoudness = 100;
  }

  // Trigger hi-hat (channel 9, note 55)
  if (hiHatVal == 1)
  {
    hiHatLoudness = 100;
  }

  // Send the MIDI note-on messages with the correct loudness values
  noteOn(9, bassArray[random(2)], bassLoudness);  
  noteOn(9, potValMapped, snareLoudness);
  noteOn(9, hatArray[random(2)], hiHatLoudness);
  noteOn(1, random(36, 58), sequenceLoudness);

  MidiUSB.flush();            
  
  // Update the beat counter and reset after 8 counts (loop through 0-7)
  counter++;
  counter = counter % 8;

  // Delay before sending the next set of MIDI messages
  delay(100);
}
