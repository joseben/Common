#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define button_IN 8
#define button_OUT 7
#define RED 10
#define GREEN 9


int flag=0;

int count=0;

void IN()
{
    count++; // increment the value
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(250);
   
}

void OUT()
{
  count--; // increment the value
    lcd.clear(); // Clear the LCD Value
    lcd.print("Person In Room:");
    lcd.setCursor(0,1); // set the cursor positon
    lcd.print(count); // Display count value
    delay(250);
    
}

void setup()
{  
  lcd.begin(16,2);

  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(button_IN, INPUT); // Assign the Button
  pinMode(button_OUT, INPUT);//Assign the Button
  pinMode(RED, OUTPUT);//Assign the LED
  pinMode(GREEN, OUTPUT);//Assign the LED
  digitalWrite(GREEN,LOW);
  digitalWrite(RED,LOW);

  lcd.clear();
  lcd.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop()
{  
  
  if(digitalRead(button_IN)==HIGH && flag==0)
  {
     flag=1;
    }

  else if(digitalRead(button_IN)==HIGH && flag==1)
  {
    IN();
    flag=0;
    }
    
  if(digitalRead(button_OUT)==HIGH && flag==1 )
      { 
        flag=0;
        IN();
      }
    
  else if(digitalRead(button_OUT)==HIGH && flag==0)
  { 
    OUT();
    
    }




   
  
  if(count>5&&count<=10)
  {
    digitalWrite(GREEN,HIGH);
    digitalWrite(RED,LOW);

  }
  
  if (count>10)
    {
      digitalWrite(GREEN,LOW);
      digitalWrite(RED, HIGH);
      
    }
  else
  {
     digitalWrite(GREEN,LOW);
     digitalWrite(RED,LOW);
    }
}
