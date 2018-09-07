//define the number of input bytes
const int inputCount=4;

char inData[inputCount]; // Allocate some space for the string
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character
int countdown = inputCount;
int recvInt = 0;

void setup()
{
   Serial.begin(9600);
   Serial.println("Serial start");
}


void loop()
{
  while(Serial.available() > 0) // Don't read unless
                                // there you know there is data
  {
      if(index < inputCount)
      {
          inChar = Serial.read(); // Read a character
          inData[index] = inChar; // Store it
          index++;
        
          countdown--;
       // if ( inData[index] == "1" ){    
        // recvInt = recvInt + pow(countdown, 2) * inChar;
        
   Serial.println("===");
        
        Serial.println(countdown);
        
    Serial.println("===");
        int test =pow( 2, countdown)+1;
        Serial.println(test);
        
        if ( inChar =='1' ){
          Serial.println("equal");
         recvInt = recvInt + test;
        }
        Serial.println(recvInt);
        //}
          //Serial.println(inData);
        if ( index == 4){ // Null terminate the string
             // Now do something with the string (but not using ==)
            //doData( inData );
            //inData = "";
//Serial.println(inData);
Serial.println(recvInt);
          index =0;
          recvInt = 0;
          countdown = inputCount;
          }
      }
  }
  //inData[index] = '\0'; // Null terminate the string
 
}

 void doData( char inData ){
  Serial.println(inData);
}
