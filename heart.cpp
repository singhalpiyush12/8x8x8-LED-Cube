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
{ //EveryOff();
  Heart();
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
void Heart()
{//38,29,20,11,18,26,35,42,50,59,52,45,38
  for(int i=0;i<72;i++)
  {
    if(i==38||i==29||i==20||i==11||i==18||i==26||i==35||i==42||i==50||i==59||i==45||i==52||i==0){registers[i]=HIGH;
    writereg();}
    else registers[i]=LOW;
  }
}
void Heart1()
{//38,29,20,11,18,26,35,42,50,59,52,45,38
  for(int i=0;i<72;i++)
  {
    if(i==38||i==29||i==20||i==11||i==18||i==26||i==35||i==42||i==50||i==59||i==45||i==19||i==27||i==28||i==36||i==37||i==44||i==52||i==51||i==43||i==0){registers[i]=HIGH;
    writereg();}
    else registers[i]=LOW;
  }
}
