
int DS_pin =51;
int LATCH_pin = 33;
int Clock_pin = 52;
boolean registers[72];
int j;int l[8];
bool right=false,left=false,up=false,down=false;
int myvector[8][64];


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
{for(int i=0;i<8;i++)
{
  for(int j=0;j<64;j++)
    myvector[i][j]=0;
}
for(int a=0;a<8;a++)
l[a]=0;
  tetris();
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
void stationary(int pillar,int level)
{ 
  myvector[level][l[level]]=pillar;
  l[level]++;
 /* for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
  */
}
void fig1(int m, int n)//one on in lower and all on in upper 
{ 
  bool p=true;bool stop=false;
  /*if(registers[j+1]==HIGH)
  {
    p=false;
  }
  */

  while(p==true& Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(30+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(30+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    registers[j]=HIGH;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    registers[j]=LOW;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      { if(k==(26+(8*n)+m))continue;
        else registers[k+8*l]=LOW;
      }
    }
    registers[j+1]=HIGH;
    writereg();
    i++;
   }

   for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }

  j++;if(j==7){stop=true;}

  if(stop==true)
  { for(int l=0;l<4;l++)
    {int b=26+(8*n)+m+8*l;
      stationary(b,j);
    }
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j-1);
        }
      }
      tetris();
  }

  }
}
void fig1comple(int m,int n)//one off on upper else on
{
  bool p=true;bool stop=false;
  while(p==true&Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(30+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(30+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    int k=(26+(8*n)+m);
    for(int l=0;l<4;l++)
    {
      registers[k+8*l]=LOW;
    }
    registers[j]=HIGH;
    writereg();
    registers[j]=LOW;
    registers[j+1]=HIGH;
    for(k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    i++;
   }

  for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a]||b+3==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }
  j++;if(j==7){stop=true;}

  if(stop==true)
  { for(int a=27+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j-1);
        }
      }
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j);
        }
      }
      tetris();
  }

  }
}
void fig2(int m,int n)//middle two on top layer on and base on
{
  bool p=true;bool stop=false;
  while(p==true&Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(30+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(30+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    int k=(26+(8*n)+m);
    for(int l=0;l<4;l++)
    {
      registers[k+8*l]=LOW;
      registers[k+3+8*l]=LOW;
    }
    registers[j]=HIGH;
    writereg();
    registers[j]=LOW;
    registers[j+1]=HIGH;
    for(k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    i++;
   }

  for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a]||b+3==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }

  j++;if(j==7){stop=true;}

  if(stop==true)
  { for(int a=27+(8*n)+m;a<29+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j-1);
        }
      }
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j);
        }
      }
      tetris();
  }

  }
}
void fig2comple(int m, int n)//lower base middle off upper base all on
{ 
  bool p=true;bool stop=false;
  while(p==true&Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(31+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(31+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    registers[j]=HIGH;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    registers[j]=LOW;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      { if(k==(26+(8*n)+m)||k==(29+(8*n)+m))continue;
        else registers[k+8*l]=LOW;
      }
    }
    registers[j+1]=HIGH;
    writereg();
    i++;
   }

  for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a]||b+3==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }

  j++;if(j==7){stop=true;}

  if(stop==true)
  { for(int l=0;l<4;l++)
    {int b=26+(8*n)+m+8*l;
      stationary(b,j);
      stationary(b+3,j);
    }
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j-1);
        }
      }
      tetris();
  }

  }
}
void fig3(int m,int n)//middle two on top layer on and base on
{
  bool p=true;bool stop=false;
  while(p==true&Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(30+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(30+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    int k=(26+(8*n)+m);
    for(int l=0;l<4;l++)
    {
      registers[k+8*l]=LOW;
      registers[k+3+8*l]=LOW;
    }
    registers[k+25]=LOW;
    registers[k+26]=LOW;
    registers[k+1]=LOW;
    registers[k+2]=LOW;

    registers[j]=HIGH;
    writereg();
    registers[j]=LOW;
    registers[j+1]=HIGH;
    for(k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    i++;
   }

  for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a]||b+3==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }

  j++;if(j==7){stop=true;}

  if(stop==true)
  { for(int l=1;l<3;l++)
    {int b=26+(8*n)+m+8*l;
      stationary(b+1,j-1);
      stationary(b+2,j);
    }
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j);
        }
      }
      tetris();
  }

  }
}
void fig3comple(int m, int n)//lower base middle off upper base all on
{ 
  bool p=true;bool stop=false;
  while(p==true&Serial.available()==0)
  { int i=0;
    while(i<1000)
   { if(down)
    { for(int k=(26+(8*(n+4))+m);k<(31+(8*(n+4))+m);k++)
      registers[k]=LOW;
      down=false;
    }
    else if(up)
    { up=false;
      for(int k=(26+(8*(n-1))+m);k<(31+(8*(n-1))+m);k++)
      registers[k]=LOW;
    }
    if(left)
    { left=false;
      int k=(30+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    else if(right)
    { right=false;
      int k=(25+(8*n)+m);
      for(int l=0;l<4;l++)
      {
        registers[k+8*l]=LOW;
      }
    }
    for(int i=0;i<8;i++)
  {int a=0;registers[i]=HIGH;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=HIGH;
  			a++;
  		}
  		writereg();
  	a=0;registers[i]=LOW;
  	while(myvector[i][a]!=0)
  		{registers[myvector[i][a]]=LOW;
  			a++;
  		}
  		writereg();	
  }
    registers[j+1]=LOW;
    registers[j]=HIGH;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      {
        registers[k+8*l]=HIGH;
      }
    }
    writereg();
    registers[j]=LOW;
    for(int k=(26+(8*n)+m);k<(30+(8*n)+m);k++)
    { for(int l=0;l<4;l++)
      { if(k==(26+(8*n)+m)||k==(29+(8*n)+m))continue;
        else if(l!=0&l!=3)registers[k+8*l]=LOW;
      }
    }
    registers[j+1]=HIGH;
    writereg();
    i++;
   }

  for(int l=0;l<4;l++)
  {int a=0;while(myvector[j+2][a]!=0)
    {int b=26+(8*n)+m+8*l;
      if(b==myvector[j+2][a]||b+3==myvector[j+2][a])
      {p=false;
      stop=true;
      }
      a++;
    }
  }

  j++;if(j==7){stop=true;}

  if(stop==true)
  {   int a=26+(8*n)+m;
      for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j);
          stationary(a+3+8*l,j);
        }
          stationary(a+8*1,j);
          stationary(a+3+8*1,j);
          stationary(a+8*2,j);
          stationary(a+3+8*2,j);
    for(int a=26+(8*n)+m;a<30+(8*n)+m;a++)
      {for(int l=0;l<4;l++)
        {
          stationary(a+8*l,j-1);
        }
      }
      tetris();
  }

  }
}
void run(int p,int m,int n)
{
  
  if(p==0)
    fig1(m,n);
  else if(p==1)
    fig1comple(m,n);
  else if(p==2)
    fig2(m,n);
  else if(p==3)
    fig2comple(m,n);
  else if(p==4)
    fig3(m,n);
  else if(p==5)
    fig3comple(m,n);
}

void tetris()
{ 
  int m=0,n=0;j=0;int p=random(0,6);run(p,m,n);
  while(Serial.available() > 0)
  {
    int control=Serial.read();

    if(control==50)
    { down=true;
      n--;if(n<-2){n = -2;down=false;run(p,m,n);}
      else run(p,m,n);
    }
    else if(control==52)
    { left=true;
      m--;if(m<-2){m = -2;left=false;run(p,m,n);}
      else run(p,m,n);
    }
    else if(control==54)
    { right=true;
      m++;if(m>2){m = 2;right=false;run(p,m,n);}
      else run(p,m,n);
    }
    else if(control==56)
    { up=true;
      n++;if(n>2){n = 2;up=false;run(p,m,n);}
      else run(p,m,n);
    }
    /*else if(control==52)
    {
      
    }
    else if(control==52)
    {
      
    }
    */
  }
}