/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
 Michael added serial auto burst function for shrimp 

  modified 8 May 2014
  by Scott Fitzgerald
 */

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
   Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("serial started");
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("ON");
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  Serial.println("OFF");  // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
 if (Serial.available() > 0) {
    //int randNumber = random(300);
    //Serial.println(randNumber); 
     char inChar = (char)Serial.read();
      if (  inChar ){
         Serial.println(inChar);
      }
 }
}
