
//define the number of input bytes
const int inputCount=4;

char inData[inputCount]; // Allocate some space for the string
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character
int countdown = inputCount;
int recvInt = 0;
int added_int = 0;
int s_input;

void setup()
{
    Serial.begin(9600);
   Serial.println("Serial start");
  //pin 3456 as input
  pinMode( 3, INPUT);
  pinMode( 4, INPUT);   
  pinMode( 5, INPUT);   
  pinMode( 6, INPUT);   
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}


void loop()
{
  
  if ( digitalRead(3)+digitalRead(4)+digitalRead(5)+digitalRead(6) != 0 ){ 
     
    s_input = get_input();
      
    if ( s_input != 0 ){
      //Serial.println(s_input);
      Serial.println(inData);
      //reset_input();
      play_midi();
    }
  }
 
}

void play_midi(){
  Serial.println(s_input);
}

void reset_input(){
  inData[inputCount]; // Allocate some space for the string
  index = 0; // Index o array; where to store the acter
  countdown = inputCount;
  recvInt = 0;
  added_int = 0;
  s_input=0;
}
 
int get_input(){
    
    inData[4];
     added_int=0;
        
     if (digitalRead(3)) { 
        added_int = added_int + (2*2*2);
        inData[0] ='1';
      }else{
        inData[0] ='0';
      }
      
       if (digitalRead(4)) { 
        added_int = added_int + 2*2; 
         inData[1] ='1';
      }else{
        inData[1] ='0';
      }
      
      if (digitalRead(5)) { 
        added_int =  added_int + 2; 
        inData[2] ='1';
      }else{
        inData[2] ='0';
      }
      
       if (digitalRead(6)) { 
        added_int = added_int + 1; 
        inData[3] ='1';
      }else{
        inData[3] ='0';
      }
        
           //in rare or error case, we recv 0000 , recvInt return 0, the var will not
           //be reset , so check and reset here
           if (inData=='0000'){
            //reset_input();
            return 0; 
           }
          return added_int;
         
}           
