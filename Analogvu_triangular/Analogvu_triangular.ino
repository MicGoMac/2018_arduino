 
const int vary_pin = 10;
const int stable_pin = 11; 
const int control_pin = A0; 

void setup() {
  pinMode(vary_pin, OUTPUT);
  /*
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("serial started");
  */
}

void loop() {
  int sensorValue = analogRead(control_pin);
  // map it to the range of the analog out:
  int outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(stable_pin, outputValue);
  
    //each loop add a random number 
    int randNumber = random(70);
     
     //try to do a saw wave
    for ( int x= 0; x <= randNumber; x++) {
             
      int brightness = (int) x;
		 
	        
      analogWrite(vary_pin, brightness);
      delay(2);
	
    }
}

