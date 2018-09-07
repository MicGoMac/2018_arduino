
/*
stepper 4 pins color code white, yellow green blue
map to pin 2-5

*/

#define IN1  2
#define IN2  3
#define IN3  4
#define IN4  5
int Steps;
boolean Direction;
//unsigned long last_time;
//unsigned long currentMillis ;
int steps_left;
long time;


String highlow=String("00000111000001");
int stepnum=0;

void setup()
{
	Serial.begin(9600);	
	Serial.println (highlow);
	pinMode(IN1, OUTPUT); 
	pinMode(IN2, OUTPUT); 
	pinMode(IN3, OUTPUT); 
	pinMode(IN4, OUTPUT);
	Steps = 0;
	Direction = true;
	steps_left=4095;
}

void loop()
{

	stepnum=stepnum+1;
	if ( stepnum >= 8){stepnum=0;}
  
	String p1= spstr( 1 );
	String p2= spstr( 2 );
	String p3= spstr( 3 );
	String p4= spstr( 4 );
	
	////Serial.println (stepnum);
	//Serial.println (p1);
	//Serial.println ( "p4-" + p4);
	////Serial.println (p1+p2+p3+p4);
	
	digitalWrite(IN1, p1.toInt() ); 
	digitalWrite(IN2, p2.toInt() );
	digitalWrite(IN3, p3.toInt() );
	digitalWrite(IN4, p4.toInt() );
	delay(1);
}

String spstr( int pin ){
  //for pin 1, start with char 1, pin 2 start with 2
  int os = (pin-1)*2;
 
    String chop=highlow.substring( os+stepnum, os + stepnum + 1);
    //int state = chop.toInt();
	return chop;
}
