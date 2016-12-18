/* 

//michael
mark out all //Serial stuff in production version
====

 Debounce
 Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 a minimum delay between toggles to debounce the circuit (i.e. to ignore
 noise).  
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached from pin 2 to +5V
 * 10K resistor attached from pin 2 to ground
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
  
 http://www.arduino.cc/en/Tutorial/Debounce
 */


// set pin numbers:
const int buttonPin = 11;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int playModeCount=5;
const int lampCount = 7;

const int xmasLed1= 3;
const int xmasLed2= 4;
const int xmasLed3= 5;
const int xmasLed4= 6;
const int xmasLed5= 7;
const int xmasLed6= 8;
const int xmasLed7= 9;
int ddlay;
int rand_pin;
int rand_pin2;
int rand_pin3;
int rand_pin4;

int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

int playMode=1;  //we have diff modes
int countbeat = 0;

int randomVals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int randomVal_length=lampCount*2;
  //put an extra xmasLed1 so it match 1-7 numbering
int xmasLeds[]={ xmasLed1, xmasLed1, xmasLed2,   xmasLed3, xmasLed4, xmasLed5, xmasLed6, xmasLed7};
//int  xmasLeds[]={ 0, 3, 4, 5, 6, 7, 8, 9};

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode( xmasLed1, OUTPUT );
  pinMode( xmasLed2, OUTPUT );  
	pinMode( xmasLed3, OUTPUT );
	pinMode( xmasLed4, OUTPUT );
	pinMode( xmasLed5, OUTPUT );
	pinMode( xmasLed6, OUTPUT );
	pinMode( xmasLed7, OUTPUT );
	
  /*
  Serial.begin(9600);
 
  while (!//Serial) {
    ; // wait for //Serial port to connect. Needed for Leonardo only
  }
  //Serial.println("//Serial started");
  */
  
  
	//  int ss=sizeof(randomVals);
	//  //Serial.println(ss);  //wtf = 28, why?
  genRan(lampCount);
}

void loop() { 
    
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
 
  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = reading;
    
    //anyway, we want it to trigger a mode change
    //modeChange();
  }
  
  // set the LED using the state of the button:
 //// digitalWrite(ledPin, buttonState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
  
  
  
	int i;
  
	switch (playMode) {
		case 1:
			//turn on one by one, then off one by one
			ddlay=200;
			 
     
			for (i = 0; i < randomVal_length/2; i++) {
				rand_pin=xmasLeds[randomVals[i]];
				digitalWrite(rand_pin, HIGH);
				//digitalWrite(ledPin, HIGH);////
				
				delay(ddlay);
			}
			for (i = 0; i < randomVal_length/2; i++) {
				rand_pin=xmasLeds[randomVals[i]];
				digitalWrite(rand_pin, LOW);	
				//digitalWrite(ledPin, LOW);
				
				delay(ddlay*2);
			}
			break; 
			
			
		case 2:
			//turn on 2 at a time
			ddlay=300;
			
			//lightup first 2
			for (i = 0; i <= 1; i++) {
				rand_pin=xmasLeds[randomVals[i]];
				digitalWrite(rand_pin, HIGH);
				//Serial.print(rand_pin);
			}
			delay(ddlay);
			
			for (i = 0; i < randomVal_length-4; i=i+2) {
			
				rand_pin=xmasLeds[randomVals[i]];
				rand_pin2=xmasLeds[randomVals[i+1]];
				rand_pin3=xmasLeds[randomVals[i+2]];
				rand_pin4=xmasLeds[randomVals[i+3]];
				
				digitalWrite(rand_pin, LOW);	
				digitalWrite(rand_pin2, LOW);
				digitalWrite(rand_pin3, HIGH);	
				digitalWrite(rand_pin4, HIGH);	

				//Serial.print(rand_pin3);
				//Serial.print(rand_pin4);

				delay(ddlay);
			}
			
			//TURN OFF last 2
			for (i = randomVal_length; i > randomVal_length-2; i--) {
				rand_pin=xmasLeds[randomVals[i]];
				digitalWrite(rand_pin, LOW);	
			}
			
			//Serial.print("\n===\n");
			
			break; 
		case 3:
			
			break;
		case 4:
			
			break; 
		case 5:
			
			break; 		
	}
   
  	countbeat++;
    /*
     if ((countbeat % 7 )==0 ){
      //Serial.print("seven\n");
    }
    */
    
   if ( countbeat >= 2 ){
		 //Serial.print("another random\n");
		 genRan(lampCount);
		 countbeat=0;
		 
   }
}

//make it 2 rand array joined together
int genRan( int LastNum ){
	//reset randomVals  
	//learned from http://www.utopiamechanicus.com/article/arduino-setup-arrays/
	memset(randomVals,0,sizeof(randomVals));
	 
	int passCounter=1;
	
	//first pass, first 7
	while (true) {
		int temp = random(0, LastNum);
		if (randomVals[temp] == 0) {         // If this number has not been generated yet...
			randomVals[temp] = passCounter;
			passCounter++;
			/*
			int i;		 
			for (i = 0; i < LastNum; i++) {
			  //Serial.print(randomVals[i]); 
			}
			//Serial.print("\n");
		  */
		} 
		
		if (passCounter > LastNum) { 
		  break;
		}
	}
	  
	 passCounter=1;
	
	//2nd pass, next 7
	while (true) {
		int temp = random(0, LastNum);
		
		if ( randomVals[temp+LastNum] == 0 ) { 
			randomVals[temp+LastNum]= passCounter; 
			passCounter++;
		}
		if (passCounter > LastNum) { 
		  break;
		}
	}


	//print result
	int i;
	for (i = 0; i < 14; i++) {
		//Serial.print(randomVals[i]); 
	}
	//Serial.print("\n");
}
 
 
void modeChange(){
  playMode++;
  if ( playMode > playModeCount ){
    playMode=1;
  }
}
