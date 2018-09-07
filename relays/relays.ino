/* 
michael's relay with serial for use with nas
 */

const int ledPin = 13;      // led connected to digital pin 13
const int r1 = 2;
const int r2 = 3;
const int r3 = 4;
const int r4 = 5;

String inputString = ""; 
boolean stringComplete = false;
boolean r1_state = true;
boolean r2_state = true;
boolean r3_state = true;
boolean r4_state = true;

int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  
  Serial.begin(9600);       // use the serial port
  //inputString.reserve(200); // reserve 200 bytes for the inputString:
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  for (int thisPin = r1; thisPin <= r4; thisPin++) {
          digitalWrite(thisPin, HIGH);
        }
        
pinMode(r1, OUTPUT);
pinMode(r2, OUTPUT);
pinMode(r3, OUTPUT);
pinMode(r4, OUTPUT);

Serial.println("started");  
}

void loop() {
  // read the sensor:
  if (Serial.available() > 0) {
     
   char inChar = (char)Serial.read();
   // Serial.println(inChar);
    switch (inChar) {
      case '1':
        r1_state = !r1_state;
        //Serial.println(inChar);
        digitalWrite(r1, r1_state);
        gotit(inChar);
        break;
      case '2':
        r2_state = !r2_state;
        //Serial.println(inChar);
        digitalWrite(r2, r2_state);
        gotit(inChar);
        break;
      case '3':
        r3_state = !r3_state;
        //Serial.println(inChar);
        digitalWrite(r3, r3_state);
        gotit(inChar);
        break;
      case '4':
      r4_state = !r4_state;
       //Serial.println(inChar);
        digitalWrite(r4, r4_state);
        gotit(inChar);
        break; 
      case '0':
        for (int thisPin = r1; thisPin <= r4; thisPin++) {
          digitalWrite(thisPin, HIGH);
        }
        gotit(inChar);
        break; 
        
      default:
         Serial.println("non action char");
         
        break;
    }
      delay(200);
  }
}

void gotit( char n) {
  Serial.println( n);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(300);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

/*
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    if ( inChar != '1' && inChar != '2' && inChar != '3' && inChar != '4'){
    	//damn str cannot compare with char+
     	//inputString = inChar;
    	stringComplete = true;
    }
    
     
  }
  
}*/

