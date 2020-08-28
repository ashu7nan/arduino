#include<LiquidCrystal.h>
LiquidCrystal lcd(D0,D1,D2,D3,D4,D5);
int mi=0;
int sec=0;
int hr=0;
int flag=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,1);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<60;i++)
  {
  lcd.print(hr,DEC);
  lcd.write(':');
  lcd.print(mi,DEC);
  lcd.write(':');
  lcd.print(sec,DEC);
  
   sec=sec+1;
  if(sec==60)
  {
    mi++;
    sec=0;
  }
  if(mi==60)
  {
    hr++;
    mi=0;
  }
   if(hr==12)
  {
    
    hr=0;
    if(flag==0)
    {
      flag=1;
    }
    else{
      flag=0;
    }
  }
  if(flag==0)
  {
    lcd.print(" AM");
  }
  else
  {
    lcd.print(" PM");
  }
  delay(1000);
  lcd.clear();
  }
}
