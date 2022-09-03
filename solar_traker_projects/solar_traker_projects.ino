#include<Servo.h>  //including library of servo motor
Servo sg90;        //initializing the variable for servo named sg90
int initial_position = 90;    //Declaring the intial position at 90
int LDR1 = A0;       //pin at which LDR1 is connected
int LDR2 = A1;       //pin at which LDR2 is connected
int error = 5;       //intializing variable for error
int servopin = 9;    //intial position at which servo motor is connected

void setup()
{
  sg90.attach(servopin);  //attach the servo on pin 9
  pinMode(LDR1,INPUT);    //Making the LDR pin as input
  pinMode(LDR2,INPUT);
  sg90.write(initial_position);  //move the servo at 90 degree
  delay(2000);           //giving the delay of 2 seconds
}
void loop()
{
  int R1 = analogRead(LDR1);
  int R2 = analogRead(LDR2);
  int diff1 = abs(R1-R2);
  int diff2 = abs(R2-R1);

  if((diff1 <= error)|| (diff2 <= error))
  { 
  }
  else{
    if(R1 > R2)
    {
      initial_position = --initial_position;
    }
    if(R1 < R2)
    {
      initial_position = ++initial_position;
    }
  }
  sg90.write(initial_position);
  delay(100);
}
