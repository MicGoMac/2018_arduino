

#include <LiquidCrystal.h>
#include "PS2Keyboard.h"

/*

http://digital-salvage.net/?p=124
*/

LiquidCrystal lcd(4, 5,  8, 9, 10, 11); //create the lcd variable

const int DataPin = 2;
const int IRQpin =  3;
+
PS2Keyboard keyboard;

void setup() {
  delay(1000);
 keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");
  
  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
}
 
void loop() {
  
  if (keyboard.available()) {
    
    // read the next key
    char c = keyboard.read();
    
    // check for some of the special keys
    if (c == PS2_ENTER) {
      Serial.println();
    } else if (c == PS2_TAB) {
      Serial.print("[Tab]");
    } else if (c == PS2_ESC) {
      Serial.print("[ESC]");
    } else if (c == PS2_PAGEDOWN) {
      Serial.print("[PgDn]");
    } else if (c == PS2_PAGEUP) {
      Serial.print("[PgUp]");
    } else if (c == PS2_LEFTARROW) {
      Serial.print("[Left]");
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    } else if (c == PS2_DELETE) {
      Serial.print("[Del]");
    } else {
      
      // otherwise, just print all normal characters
      Serial.print(c);
    }
  }
  
  delay(100);
  lcd.print("Work It");          //print...
  lcd.clear();                   //clear LCD, since we are still on 2nd line...
  lcd.home();                    //set the cursor the top left
}
