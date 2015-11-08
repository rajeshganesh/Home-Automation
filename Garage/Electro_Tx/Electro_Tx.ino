#include <ELECHOUSE_CC1101.h>



#define size 1
#define DOOR_OPEN_PIN       4
#define DOOR_OPEN_MESSAGE   0x99
#define DOOR_CLOSED_MESSAGE 0x45

byte TX_buffer[size]={0};
byte i;

void setup()
{
  Serial.begin(9600);
  ELECHOUSE_cc1101.Init();

  pinMode(DOOR_OPEN_PIN,INPUT);
  for(i=0;i<size;i++)
  {
     TX_buffer[i]=DOOR_OPEN_MESSAGE;
  }
}

void loop()
{

  while(1)
  {
    if(digitalRead(DOOR_OPEN_PIN))
    {
      TX_buffer[0]=DOOR_OPEN_MESSAGE;
      ELECHOUSE_cc1101.SendData(TX_buffer,size);
      //delay(1);
    }
  
    else
    {
      TX_buffer[0]= DOOR_CLOSED_MESSAGE;
      ELECHOUSE_cc1101.SendData(TX_buffer,size);
  
      
    }

    delay(5000);
  }
  
}

