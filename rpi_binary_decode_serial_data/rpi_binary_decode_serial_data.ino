int inData[36];
char inChar;
int index=0;
int input;
int pin3;

void setup()
{
	Serial.begin(9600);
	Serial.println("Serial start");
  
	pinMode( 3, INPUT);
	pinMode( 4, INPUT);   
	pinMode( 5, INPUT);   
	pinMode( 6, INPUT);  
}

void loop()
{
	for( $i=3; $i<=6; $i++){
		index++;
     	//pin3 = digitalRead(i);
		checknote(digitalRead(i));	
 		
 		if (index>5){
 			index=0;
 		}
	}

	delay(500);
}
 
void checknote( int x){
  	//Serial.println(x);
    if (inData[index] == x){
     
    }else if (inData[index] > x){
      	inData[index] =0;
        Serial.println(index);
        Serial.println("turn 0");

    }else if (inData[index] < x){
      	inData[index] =1;
        Serial.println(index);
        Serial.println("turn 1");
      
    }
  
}