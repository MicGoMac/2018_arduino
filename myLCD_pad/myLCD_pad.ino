

#include <LiquidCrystal.h>
#include "PS2Keyboard.h"

/*

http://digital-salvage.net/?p=124
*/

LiquidCrystal lcd(4, 5,  8, 9, 10, 11); //create the lcd variable

const int DataPin = 2;
const int IRQpin =  3;
int count;

PS2Keyboard keyboard;

void setup() {
  delay(1000);
 keyboard.begin(DataPin, IRQpin);
  
  lcd.clear();                    //clear the LCD during setup
  lcd.begin(16,2);                //define the columns (16) and rows (2)
  lcd.print("Press key");          //print...
  count=0;
}
 
void loop() {
  
  if (keyboard.available()) {
     lcd.setCursor(0,0);
    // read the next key
    //char c = keyboard.read();
    
    // not work
    byte b = keyboard.read();
    
     if(b == 13 ) {
        lcd.print("[enter]      ");
     }
     
     
    // check for some of the special keys
    if (c == PS2_ENTER) {
      lcd.println();
    } else if (c == PS2_TAB) {
      lcd.print("[Tab]      ");
    } else if (c == PS2_ESC) {
      lcd.print("[ESC]      ");
    } else if (c == PS2_PAGEDOWN) {
      lcd.print("[PgDn]     ");
    } else if (c == PS2_PAGEUP) {
      lcd.print("[PgUp]    ");
    } else if (c == PS2_LEFTARROW) {
      lcd.print("[Left]    ");
    } else if (c == PS2_RIGHTARROW) {
      lcd.print("[Right]    ");
    } else if (c == PS2_UPARROW) {
      lcd.print("[Up]   ");
    } else if (c == PS2_DOWNARROW) {
      lcd.print("[Down]   ");
    } else if (c == PS2_DELETE) {
      lcd.print("[Del]   ");
    } else if (c == PS2_ENTER) {
      lcd.print("[PS2_ENTER]");
    } else if (c == PS2_END) {
      lcd.print("[PS2_END]");
    } else if (c == PS2_HOME) {
      lcd.print("[PS2_HOME]");
    } else if (c == PS2_INSERT) {
      lcd.print("[PS2_INSERT]");      
    } else {
       
      String thisString = String(c);
      lcd.print( thisString + "         ");
    }
  }
  
   lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  
  /*
  lcd.print("Timing clock    ");    // change this text to whatever you like.  keep it clean.
  lcd.setCursor(0,1);           // set cursor to column 0, row 1
  lcd.print(count); 
  delay(1000);
  */
  count++;
  if (count>1000){
   count=0; 
  }
  //lcd.clear();                   //clear LCD, since we are still on 2nd line...
  //lcd.home();                    //set the cursor the top left
}
