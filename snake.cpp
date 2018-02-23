int DS_pin =51;
int LATCH_pin = 33;
int Clock_pin = 52;
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

/*int n=2;
int a[n]={1,3};//levels
int b[n]={1,3};//rows
int c[n]={1,1};//column
*/
void loop()
{
  //OnOnebyOne();
  //OffOnebyOne();
  //Flicker();
  //OnLayerwise();
  //OffLayerwise();
  //RandomRain();
  //Boundaries();
  //Walls();
  //Spiral();
  //LetterP();
  //LED(1,1,1);
  //Converge();
  //MultiLed(a,b,c);
  //while(Serial.available()==0){}
  Snake();

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
void Snake()
{ //LED(0,0,0);
  int n=1;int l=random(0,8);int p=random(8,72);
  EveryOff();  
  registers[l]=HIGH;registers[p]=HIGH;
  writereg();
  delay(2000);
  int a[100],b[100],c[100];a[0]=0;b[0]=0;c[0]=0;
  while(Serial.available() > 0)
  { 
    dir=Serial.read();int x;
    Serial.println(dir);
    if(dir==50)
    { while(true)
       {
        //if(x==53)
          //{c[n-1-i]--;i++;a[i]++;}
          for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
          c[n-1]--;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2];b[n-1]=b[n-2];c[n-1]=c[n-2];
            registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(c[n-1]<0)
      {Serial.println("GameOver!!!");break;}
       }
    }
    else if(dir==56)
    {
       while(true)
       {for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
        c[n-1]++;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2];b[n-1]=b[n-2];c[n-1]=c[n-2]+1;led(a,b,c,n,l,p);registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(c[n-1]>7)
      {Serial.println("GameOver!!!");break;}
       }
    }
    else if(dir==52)
    {
       while(true)
       {for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
        b[n-1]--;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2];b[n-1]=b[n-2];c[n-1]=c[n-2];led(a,b,c,n,l,p);registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(b[n-1]<0)
      {Serial.println("GameOver!!!");break;}
       }
    }
    else if(dir==54)
    {
       while(true)
       {for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
        b[n-1]++;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2];b[n-1]=b[n-2]+1;c[n-1]=c[n-2];led(a,b,c,n,l,p);registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(b[n-1]>7)
      {Serial.println("GameOver!!!");break;}
       }
    }
    else if(dir==48)
    {
       while(true)
       {for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
        a[n-1]--;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2];b[n-1]=b[n-2];c[n-1]=c[n-2];led(a,b,c,n,l,p);registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(a[n-1]<0)
      {Serial.println("GameOver!!!");break;}
       }
    }
    else if(dir==53)
    {
       while(true)
       {for(int i=0;i<n-1;i++)
            {a[i]=a[i+1];b[i]=b[i+1];c[i]=c[i+1];}
        a[n-1]++;
        led(a,b,c,n,l,p);
        //delay(2000);
        if(7-a[n-1]==l&(((8*c[n-1])+b[n-1])+8)==p)
          {n++;a[n-1]=a[n-2]+1;b[n-1]=b[n-2];c[n-1]=c[n-2];led(a,b,c,n,l,p);registers[l]=LOW;registers[p]=LOW;
            l=random(0,8);p=random(8,72);
              registers[l]=HIGH;registers[p]=HIGH;
              writereg();x=dir;}
        if(Serial.available()>0)
          break;
      if(a[n-1]>7)
      {Serial.println("GameOver!!!");break;}
       }
    }
  }
}
void led(int a[],int b[],int c[],int n,int l,int p)
{int i=0;
  while(i<20*(15-n))
  { for(int j=0;j<n;j++)
    {if((7-a[j])!=l&(((8*c[j])+b[j])+8)!=p)
  {registers[7-a[j]]=HIGH;
  registers[((8*c[j])+b[j])+8]=HIGH;
  registers[l]=LOW;registers[p]=LOW;
  writereg();
  registers[7-a[j]]=LOW;
  registers[((8*c[j])+b[j])+8]=LOW;
  registers[l]=HIGH;registers[p]=HIGH;
  writereg();
  }
  else if((7-a[j])!=l&(((8*c[j])+b[j])+8)==p)
  {registers[7-a[j]]=HIGH;
  registers[((8*c[j])+b[j])+8]=HIGH;
  registers[l]=LOW;
  writereg();
  registers[7-a[j]]=LOW;
  registers[((8*c[j])+b[j])+8]=HIGH;
  registers[l]=HIGH;
  writereg();
  }
  else if((7-a[j])==l&(((8*c[j])+b[j])+8)!=p)
  {registers[7-a[j]]=HIGH;
  registers[((8*c[j])+b[j])+8]=HIGH;
  registers[p]=LOW;
  writereg();
  registers[((8*c[j])+b[j])+8]=LOW;
  registers[p]=HIGH;
  writereg();
  }
}
  i++;
  }
}
