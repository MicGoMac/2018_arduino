/*
 
 * note: midi work only with Leonardo
 * 
 * MIDIUSB_test.ino
 *
 * Created: 4/6/2015 10:47:08 AM
 * Author: gurbrinder grewal
 * Modified by Arduino LLC (2015)
 * 
 * arduino communicate with  rpi through pins
 */ 
const int in_check1= 3;
const int in_check2= 4;
const int in_check3= 5;
const int in_check4= 6;

//keep that in array for easy expansion
in_pins = ["in_check1", "in_check2", "in_check3", "in_check4"];

#include "MIDIUSB.h"

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

char decode_rpi( char bin_string){
	char bin_code = check_pin_states();
}

char check_pin_states(){
	//loop through the input pins
	bin_string="";
	int i;
	for (i = 0; i < sizeof(in_pins); i = i + 1) {
	    if(digitalRead(in_pins[i]) == HIGH){
	    	bin_string = bin_string + "1";
	    }else{
	    	bin_string = bin_string + "0";	    
	    }
	}
	return bin_string;
}

void setup() { 
	pinMode( in_check1, INPUT );
	pinMode( in_check2, INPUT );  
	pinMode( in_check3, INPUT );
	pinMode( in_check4, INPUT );
	
  Serial.begin(115200);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {
  Serial.println("Sending note on");
  noteOn(0, 48, 64);   // Channel 0, middle C, normal velocity
  MidiUSB.flush();
  delay(500);
  Serial.println("Sending note off");
  noteOff(0, 48, 64);  // Channel 0, middle C, normal velocity
  MidiUSB.flush();
  delay(1500);

  // controlChange(0, 10, 65); // Set the value of controller 10 on channel 0 to 65
}

