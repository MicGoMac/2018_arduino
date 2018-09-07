 
const int lowestPin = 10;
const int highestPin = 11;
const int pi=3141;

void setup() {
  // set pins 2 through  as outputs:
  for (int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
  /*
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("serial started");
  */
}

void loop() {
    //each loop add a random number 
    int randNumber = random(70);
    
    for ( float x= 0; x <= 2*pi; x++) {
          
                float mx = x/1000;
                
                //need a more varying sin result
                //sin(x/30)*30 + sin(x/2)*30 +sin(x/60)*50
		float  f=sin(mx)*100 + sin(mx/3)*50+randNumber;

		//float  brightness=sin(x)*10+sin(x/2+1)*10;
                
                //Serial.println(f);
                
		int brightness = (int) f;
		analogWrite(11, brightness);
	  
		analogWrite(10, brightness);
		delay(2);
		x=x+7;
    }
}

