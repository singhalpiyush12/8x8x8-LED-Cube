int DS_pin =51;
int LATCH_pin = 33;
int Clock_pin = 52;
boolean registers[72];
int direction;
void setup()
{ Serial.begin(9600);
  pinMode(DS_pin, OUTPUT);
  pinMode(LATCH_pin, OUTPUT);
  pinMode(Clock_pin, OUTPUT);
  writereg();
}


void writereg()
{
  digitalWrite(LATCH_pin, LOW);

  for (int i = 72 ; i>=0 ; i--)
  {
    digitalWrite(Clock_pin, LOW);
    digitalWrite(DS_pin, registers[i]);
    //dela(10);
    digitalWrite(Clock_pin, HIGH);
   // delay(10);
  }

  digitalWrite(LATCH_pin, HIGH);

}
void loop()
{ EveryOff();
  boundary();
}
void EveryOff()
{
  for(int i=0;i<72;i++)
    {
      registers[i]=LOW;
      //delay(100);
      writereg();
    }  
}
void boundary()
{ for(int i=0;i<3;i++)
  {
    if(i==0)
    {registers[7]=HIGH;
    registers[8]=HIGH;
    writereg();
    delay(100);
    }
    if(i==1)
    {
        registers[6]=HIGH;
        registers[9]=HIGH;
        registers[16]=HIGH;
        registers[17]=HIGH;
        writereg();
        delay(100);
    }
    if(i==2)
    { registers[6]=LOW;
      registers[9]=LOW;
      registers[16]=LOW;
      registers[17]=LOW;
      int j=0;
      registers[5]=HIGH;
      while(j<200)
      { registers[6]=HIGH;
        registers[24]=HIGH;
        registers[26]=HIGH;
        registers[10]=HIGH;
        registers[9]=LOW;
        registers[16]=LOW;
        registers[25]=LOW;
        registers[18]=LOW;
        writereg();
        registers[6]=LOW;
        registers[24]=LOW;
        registers[26]=LOW;
        registers[10]=LOW;
        registers[9]=HIGH;
        registers[16]=HIGH;
        registers[25]=HIGH;
        registers[18]=HIGH;
        writereg();
        j++;
      }
    }
    if(i==3)
    {

    }
  }
}