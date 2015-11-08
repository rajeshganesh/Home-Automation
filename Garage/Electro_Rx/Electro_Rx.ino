#include <Servo.h>

#include <ELECHOUSE_CC1101.h>

#define DOOR_OPEN_MESSAGE 0x99
#define DOOR_CLOSE_MESSAGE 0x45

//Servo myservo;  // create servo object to control a servo

//int potpin = 0;  // analog pin used to connect the potentiometer
//int val;    // variable to read the value from the analog pin
int pos = 0;
void setup()
{
  Serial.begin(9600);
  ELECHOUSE_cc1101.Init();
  ELECHOUSE_cc1101.SetReceive();
//  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
//  myservo.write(0);
//  myservo.detach();
  pinMode(9, OUTPUT);
}

byte RX_buffer[1]={0};
byte size,i,flag;
bool firstMessage = true;
unsigned long openTime;

void loop()
{
  if(ELECHOUSE_cc1101.CheckReceiveFlag())
  {
    size=ELECHOUSE_cc1101.ReceiveData(RX_buffer);
    if(RX_buffer[0] == DOOR_OPEN_MESSAGE)
    {
      Serial.print("Open");
      Serial.println("");
      digitalWrite(9, HIGH);
//      if(firstMessage)
//      {
//        openTime = millis();
//        firstMessage = false;
//
//        Serial.print("Door opened");
//        Serial.println("");
//        //delay(10000);
//      }
//      else
//      {
//        if((millis() - openTime) > 20000)
//        {
//          Serial.print("Start Motor");
//          Serial.println("");
//          //StartMotor();
//          firstMessage = true;
//        }     
//      }
    }
    else if(RX_buffer[0] == DOOR_CLOSE_MESSAGE)
    {
      Serial.print("Close");
      Serial.println("");
      digitalWrite(9, LOW);
//      if(!firstMessage)
//      {
//        Serial.print("Door closed by Rajesh");
//        Serial.println("");
//        firstMessage = true;
//      }
    }
    
    ELECHOUSE_cc1101.SetReceive();
  }
  
}
//#define angle 50
//void StartMotor(){
//  Serial.println("Entering Start Motor");
//  myservo.attach(9);
//  for(pos = 0; pos <= angle; pos += 1) // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(200);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(2000);
//  for(pos = angle; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(200);                       // waits 15ms for the servo to reach the position 
//  } 
//  delay(2000);
//  myservo.detach();
//  
//
//
//  Serial.println("Exiting Start Motor");
//}


