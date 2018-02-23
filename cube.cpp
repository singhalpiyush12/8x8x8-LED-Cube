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
  Diverge();
  Converge();
  cube0();
  cube1();
  cube2();
  cube3();
}
void Converge()
{
  //EveryOn();
  //delay(500);
  for(int i=0;i<4;i++)
  { registers[i]=LOW;
      registers[7-i]=LOW;
      int a=8*(i+1);
      int b=8*(8-i);
      for(int j=8;j<72;j++)
      { 
        if((j>(a-1)&j<(a+8))||(j>(b-1)&j<(b+8))||(j%8==i)||(j%8==(7-i)))
        {
            registers[j]=LOW;
            writereg();
        }
      }
      delay(180);
  }
}
void Diverge()
{
  EveryOff();
  //delay(500);
  for(int i=3;i>=0;i--)
  { registers[i]=HIGH;
      registers[7-i]=HIGH;
      int a=8*(i+1);
      int b=8*(8-i);
      for(int j=0;j<4-i;j++)
      {
        registers[a+3-j]=HIGH;
        registers[a+4+j]=HIGH;
        registers[b+3-j]=HIGH;
        registers[b+4+j]=HIGH;
        registers[a+i+8*(j+1)]=HIGH;
        registers[b+i-8*(j+1)]=HIGH;
        registers[a+7-i+8*(j+1)]=HIGH;
        registers[b+7-i-8*(j+1)]=HIGH;
      }
      writereg();
      delay(180);
  }
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
void cube0()
{ EveryOff();
  for(int i=0;i<8;i++)
  {
    registers[7-i]=HIGH;
    for(int j=0;j<=i;j++)
    {
    registers[8*(i+1)+j]=HIGH;
    registers[8+i+8*j]=HIGH;
    }
    writereg();
    delay(100);
  }
  for(int i=7;i>=0;i--)
  {
    registers[7-i]=LOW;
    for(int j=0;j<=i;j++)
    {
    registers[8*(i+1)+j]=LOW;
    registers[8+i+8*j]=LOW;
    }
    writereg();
    delay(100);
  }
}
void cube1()
{ //EveryOff();
  for(int i=0;i<8;i++)
  {
    registers[7-i]=HIGH;
    for(int j=0;j<=i;j++)
    {
    registers[8*(8-i)+j]=HIGH;
    registers[64+i-8*j]=HIGH;
    }
    writereg();
    delay(100);
  }
  for(int i=7;i>=0;i--)
  {
    registers[7-i]=LOW;
    for(int j=0;j<=i;j++)
    {
    registers[8*(8-i)+j]=LOW;
    registers[64+i-8*j]=LOW;
    }
    writereg();
    delay(100);
  }
}
void cube2()
{
  for(int i=0;i<8;i++)
  {
    registers[7-i]=HIGH;
    for(int j=0;j<=i;j++)
    {
    registers[8*(9-i)-j-1]=HIGH;
    registers[71-i-8*j]=HIGH;
    }
    writereg();
    delay(100);
  }
  for(int i=7;i>=0;i--)
  {
    registers[7-i]=LOW;
    for(int j=0;j<=i;j++)
    {
    registers[8*(9-i)-j-1]=LOW;
    registers[71-i-8*j]=LOW;
    }
    writereg();
    delay(100);
  }
}
void cube3()
{
  for(int i=0;i<8;i++)
  {
    registers[7-i]=HIGH;
    for(int j=0;j<=i;j++)
    {
    registers[8*(i+2)-j-1]=HIGH;
    registers[15-i+8*j]=HIGH;
    }
    writereg();
    delay(100);
  }
  for(int i=7;i>=0;i--)
  {
    registers[7-i]=LOW;
    for(int j=0;j<=i;j++)
    {
    registers[8*(i+2)-j-1]=LOW;
    registers[15-i+8*j]=LOW;
    }
    writereg();
    delay(100);
  }
}