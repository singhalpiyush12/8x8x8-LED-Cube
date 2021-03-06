int DS_pin =23;
int LATCH_pin = 22;
int Clock_pin = 24;
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
  effect();
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
void effect()
{
  while(true)
  {
    for(int i=0;i<4;i++)
      { registers[i]=HIGH;
        registers[7-i]=HIGH;
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        registers[i]=LOW;
        registers[7-i]=LOW;
        for(int j=i;j<8;j++)
        {
        registers[8*(i+1)+j]=LOW;
        registers[8*(8-i)+j]=LOW;
        registers[8*(i+1)+i+8*(j-i)]=LOW;
        registers[8*(i+1)+7-i+8*(j-i)]=LOW;
        }
        writereg();
      }
  }
}
