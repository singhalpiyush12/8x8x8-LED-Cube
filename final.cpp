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
/*int n=2;
int a[n]={1,3};//levels
int b[n]={1,3};//rows
int c[n]={1,1};//column
*/
void loop()
{
  //OnOnebyOne();
  //OffOnebyOne();
  Flicker();
  //EveryOn();
  OnLayerwise();
  OffLayerwise();
  RandomRain();
  Boundaries();
  Walls();
  //Spiral();
  //LetterP();
  //LED(1,1,1);
  Diverge();
  Converge();
  //MultiLed(a,b,c);
  cube0();
  cube1();
  cube2();
  cube3();
  }

void EveryOn()
{
  for(int i=0;i<72;i++)
    {
      registers[i]=HIGH;
      //delay(100);
      writereg();
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
void OnOnebyOne()
{ EveryOff();
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      for(int k=0;k<8;k++)
      {
        registers[7-i] = HIGH;
        registers[((8*k)+j)+8] = HIGH;
        writereg();
        delay(100);
      }
    }
  }
}
void OffOnebyOne()
{ EveryOn();
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      for(int k=0;k<8;k++)
      {
        registers[7-i] = LOW;
        registers[((8*k)+j)+8] = LOW;
        writereg();
        delay(100);
      }
    }
  }
}
void Flicker()
{ EveryOff();
  for(int i=0;i<10;i++)
  {
    EveryOn();
    delay(10);
    EveryOff();
    delay(10);
  }
}
void OnLayerwise()
{ EveryOff();
  for(int i=8;i<72;i++)
  {
    registers[i]=HIGH;
    writereg();
  }
  for(int i=0;i<8;i++)
  {
    registers[i]=HIGH;
    writereg();
    delay(100);
  }
}
void OffLayerwise()
{ EveryOn();
  for(int i=0;i<8;i++)
  {
    registers[i]=LOW;
    writereg();
    delay(100);
  }
}
void OnColumnwise()
{ EveryOff();
  for(int i=0;i<8;i++)
  {
    registers[i]=HIGH;
    writereg();
  }
  for(int i=8;i<72;i++)
  {
    registers[i]=HIGH;
    writereg();
    delay(100);
  }
}
void OffColumnwise()
{ EveryOn();
  for(int i=8;i<72;i++)
  {
    registers[i]=LOW;
    writereg();
    delay(100);
  }
}
void RandomRain()
{ EveryOff();
  for(int i=0;i<30;i++)
  {
    int rand=random(8,71);
    registers[rand]=HIGH;
    writereg();
  }
  for(int i=7;i>=0;i--)
  {
    registers[i]=HIGH;
    writereg();
    delay(100);
    registers[i]=LOW;
    writereg();
    delay(10);
  }
}
void Boundaries()
{ EveryOff();
  registers[0]=HIGH;
  registers[7]=HIGH;  
  writereg();
  int i=0;
  while(i<300)
  { for(int j=1;j<7;j++)
    registers[j]=HIGH;
    for(int i=8;i<72;i++)
    {if((i<16&i>7)||(i<72&i>63)||(i%8==0)||(i%8==7))
    {registers[i]=LOW;}
    if(i==8||i==15||i==71||i==64)
      registers[i]=HIGH;
    }
    writereg();
    for(int j=1;j<7;j++)
    registers[j]=LOW;
    for(int i=8;i<72;i++)
    {if((i<16&i>7)||(i<72&i>63)||(i%8==0)||(i%8==7))
    {registers[i]=HIGH;}
    }
    writereg();
    i++;
  }
}
void Walls()
{
  for(int i=0;i<8;i++)
    {registers[i]=HIGH;
     writereg();
    }
  for(int i=8;i<72;i++)
  { if((i<16&i>7)||(i<72&i>63)||(i%8==0)||(i%8==7))
    {registers[i]=HIGH;
    writereg();
    delay(50);
    }
    else
    {registers[i]=LOW;
      writereg();}
  }
}
void Spiral()
{ for(int j=0;j<8;j++)
  { 
    if(j%2==0)
    {for(int i=0;i<8;i++)
    { //EveryOff();
      LED(0,i,j);
      registers[8*j+i+8]=LOW;
      writereg();
    } 
    }
    else
      { 
        for(int i=7;i>=0;i--)
        { //EveryOff();
          LED(0,i,j);
          registers[8*j+i+8]=LOW;
          writereg();
        }
      }
  }
}
void LetterP()
{
  registers[0]=HIGH;
  registers[1]=HIGH;
  writereg();
  for(int i=8;i<72;i++)
    {if(i%8==2||(i>66&i<70)||(i%8==5&i>32)||(i>34&i<37))
      { registers[i]=HIGH;
        writereg();
      }
      else
      {
        registers[i]=LOW;
        writereg();
      }
    }
    delay(1000);
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
void MultiLed(int level[],int row[],int column[],int n)
{ EveryOff();
  /*for(int i=0;i<72;i++)
  {
    if(i==(7-level[0])||i==(((8*column[0])+row[0])+8)||i==(7-level[1])||i==(((8*column[1])+row[1])+8))
      continue;
    else
    { registers[i]=LOW;
      writereg();
    }
  }
  */
  while(true)
  { for(int i=0;i<n;i++)
    {
    registers[7-level[i]]=HIGH;
    registers[((8*column[i])+row[i])+8]=HIGH;
    writereg();
    registers[7-level[i]]=LOW;
    registers[((8*column[i])+row[i])+8]=LOW;
    writereg();
    /*registers[7-level[1]]=HIGH;
    registers[((8*column[1])+row[1])+8]=HIGH;
    writereg();
    registers[7-level[1]]=LOW;
    registers[((8*column[1])+row[1])+8]=LOW;
    writereg();
    */
    }
  }
}
void Diagonal()
{
  int n=8;
  int a[n];//levels
  int b[n];//rows
  int c[n];//column
  for(int i=0;i<n;i++)
  { a[i]=i;b[i]=i;c[i]=i;}
    MultiLed(a,b,c,n);
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
void Folder()
{

} 
void Circle(){
  for(int i=0;i<72;i++)
  {
    if(i==10||i==11||i==12||i==17||i==24||i==32||i==40||i==49||i==58||i==59||i==60||i==53||i==46||i==38||i==30||i==21||i==0){registers[i]=HIGH;
    writereg();}
    else registers[i]=LOW;
  }
}