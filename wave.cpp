int DS_pin =23;
int LATCH_pin = 22;
int Clock_pin = 24;
boolean registers[72];
int dir;


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
//Single Led Function
void LED(int level, int row, int column){
  if(level<0)
    level=0;
  if(level>7)
    level=7;
  if(row<0)
    row=0;
  if(row>7)
    row=7;
  if(column<0)
    column=0;
  if(column>7)
    column=7;
 registers[7-level] = HIGH;
 registers[((8*column)+row)+8] = HIGH;
   for(int i =71 ; i>=0 ; i--)
  {
    if(i==(7-level)||i==(((8*column)+row)+8))
    continue;
    registers[i] = LOW;
    //delay(100);
    writereg();
  }

}


void loop()
{//EveryOff();
  wave();
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
/*void wave()
{ //EveryOff();
  int a[8];bool increase,decrease;
  for(int i=0;i<8;i++)
  {
    registers[i]=HIGH;
    for(int j=0;j<8;j++)
    {registers[8*(j+1)+7-i]=HIGH;}
    writereg();
    registers[i]=LOW;
    for(int j=0;j<8;j++)
    {registers[8*(j+1)+7-i]=LOW;}
    writereg();
  }
}
*/
void wave()
{ //
  int a[8];bool increase[8];
for(int i=0;i<8;i++)
{a[i]=i;if(i>0)increase[i]=false;
else increase[i]=true;}
int i=0;
  while(i<8)
  { /*for(int j=0;j<8;j++)
    {if(a[j]==0){increase=true;decrease=false;}
     if(a[j]==7){decrease=true;increase=false;}
     if(increase)
    }
    */int k=0;
    while(k<3)
    {registers[a[i]]=HIGH;
    for(int j=0;j<8;j++)
    {registers[8*(j+1)+7-i]=HIGH;}
    writereg();
    registers[a[i]]=LOW;
    for(int j=0;j<8;j++)
    {registers[8*(j+1)+7-i]=LOW;}
    writereg();
    k++;
    }
    if(a[i]==0)increase[i]=true;
    if(a[i]==7)increase[i]=false;
    if(increase[i])a[i]++;
    else a[i]--;
    i++;
    if(i==8)
    i=0;
  }
}
