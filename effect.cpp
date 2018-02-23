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
  effect();
}
void EveryOff()
{
  for(int i=0;i<72;i++)
    {
      registers[i]=LOW;
      //delay(25);
      writereg();
    }  
}
void effect()
{ int k=0;
  while(k<25)
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
    k++;
  }
  k=0;
  while(k<25)
  { registers[0]=LOW;
    registers[7]=LOW;
    for(int i=0;i<4;i++)
      { if(i!=0)
        {registers[i]=HIGH;
        registers[7-i]=HIGH;
        }
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        if(i!=0)
        {registers[i]=LOW;
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
    k++;
  }
  k=0;
  while(k<25)
  { registers[1]=LOW;
    registers[6]=LOW;
    for(int i=0;i<4;i++)
      { if(i!=0&i!=1)
        {registers[i]=HIGH;
        registers[7-i]=HIGH;
        }
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        if(i!=0&i!=1)
        {registers[i]=LOW;
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
    k++;
  }
  k=0;
  while(k<25)
  { registers[2]=LOW;
    registers[5]=LOW;
    for(int i=0;i<4;i++)
      { if(i!=0&i!=1&i!=2)
        {registers[i]=HIGH;
        registers[7-i]=HIGH;
        }
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        if(i!=0&i!=1&i!=2)
        {registers[i]=LOW;
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
    k++;
  }
  k=0;
  while(k<25)
  { 
    for(int i=0;i<4;i++)
      { if(i!=0&i!=1)
        {registers[i]=HIGH;
        registers[7-i]=HIGH;
        }
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        if(i!=0&i!=1)
        {registers[i]=LOW;
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
    k++;
  }
  k=0;
  while(k<25)
  { 
    for(int i=0;i<4;i++)
      { if(i!=0)
        {registers[i]=HIGH;
        registers[7-i]=HIGH;
        }
        for(int j=i;j<8-i;j++)
        {
        registers[8*(i+1)+j]=HIGH;
        registers[8*(8-i)+j]=HIGH;
        registers[8*(i+1)+i+8*(j-i)]=HIGH;
        registers[8*(i+1)+7-i+8*(j-i)]=HIGH;
        }
        writereg();
        if(i!=0)
        {registers[i]=LOW;
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
    k++;
  }
  effect();
}