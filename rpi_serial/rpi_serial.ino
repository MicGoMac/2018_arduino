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
}


void loop()
{

  // Don't read unless there you know there is data
  while(Serial.available() > 0) {
    inChar = Serial.read(); // Read a character
    s_input = get_input();
      
    if ( s_input != 0 ){
      //Serial.println("----");
      Serial.println(s_input);
      //Serial.println(inData);
      //Serial.println("===");
      reset_input();
    //play_midi();
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
    if (inChar != '0' && inChar !='1'){
      return 0;
    }
  inData[index] = inChar; // Store it
          index++;
         
     if (countdown==4 && inChar == '1') { 
        added_int = (2*2*2) ; 
      }
      
       if (countdown==3 && inChar == '1') { 
        added_int = 2*2; 
      }
       if (countdown==2 && inChar == '1') { 
        added_int =  2; 
      }
       if (countdown==1 && inChar == '1') { 
        added_int =  1; 
      }
      
      //Serial.println(added_int);
      countdown--;
      recvInt = recvInt + added_int;

      //reset this asap
      added_int = 0;
  
        if ( index == 4 ){

           //in rare or error case, we recv 0000 , recvInt return 0, the var will not
           //be reset , so check and reset here
           if (recvInt==0){
            reset_input();
           }
          return recvInt;
        }else{
              return 0; 
        }
}           
