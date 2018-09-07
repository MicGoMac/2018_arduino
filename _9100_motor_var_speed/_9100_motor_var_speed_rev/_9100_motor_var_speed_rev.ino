/*
I change it as to the other demo.
direction is controlled by reverse the pin values

all output are pwm analogue

*/
// L9110 connections
#define L9110_B_IA 10 // Pin D10 --> Motor B Input A
#define L9110_B_IB 11 // Pin D11 --> Motor B Input B
 
// Motor Speed & Direction
#define MOTOR_B_1A L9110_B_IA // Motor PWM Speed
#define MOTOR_B_1B L9110_B_IB // Motor Direction
  
 
void setup ()  { 
 pinMode( MOTOR_B_1B, OUTPUT );
 pinMode( MOTOR_B_1A, OUTPUT );
 analogWrite( MOTOR_B_1B, 0 ); // Set motor to off
 analogWrite( MOTOR_B_1A, 0 );
 pinMode( 13, OUTPUT );
}
 
void loop ()  {
   digitalWrite(13, HIGH); 
 	analogWrite( MOTOR_B_1B, 0 ); // turn motor off
	analogWrite( MOTOR_B_1A, 0 );
	delay(3000);
	 digitalWrite(13, LOW); 
	// forward
	for( int i=50; i<= 250; i++){
     
		analogWrite( MOTOR_B_1B, 0 ); // direction = forward
		analogWrite( MOTOR_B_1A, i ); //  
		delay(300);
		i=i+5;
	 }

   for( int i=240; i>= 59; i--){
    
   analogWrite( MOTOR_B_1B, 0 ); // direction = forward
    analogWrite( MOTOR_B_1A, i ); //  
    delay(300);
    i=i-5;
   }
	 /*
	analogWrite( MOTOR_B_1B, 0 ); // turn motor off
	analogWrite( MOTOR_B_1A, 0 );
	delay(1000);
	
	
	for( int i=20; i<= 200; i++){
		analogWrite( MOTOR_B_1B, i ); // direction = reverse
		analogWrite( MOTOR_B_1A, 0 ); // PWM speed = 20 and up
		delay(300);
		i=i+5;
	}

  for( int i=180; i>= 0; i--){
     
   analogWrite( MOTOR_B_1B, i ); // direction = forward
    analogWrite( MOTOR_B_1A, 0 ); //  
    delay(300);
    i=i-5;
   }
*/

}
