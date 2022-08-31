#include <LiquidCrystal.h>

int RS = 8,EN = 9,DB4 = 10,DB5 = 11,DB6 = 12,DB7 = 13;
LiquidCrystal lcd(RS,EN,DB4,DB5,DB6,DB7);

int NB_OF_COULOUMS = 16;
int NB_OF_ROWS     =  2;
 
int CONTRAST_PIN =   6;//Contrast pin for the LCD.
int SLIDESWITCH  =   5;//Controller switch of the game.
int PUSHBUTTON   =   4;//Starter button for the game.
int PIEZO        =   3;//Buzzer indicating "Game Over".
int TIME         = 125;//Delay time.

int POTENTIOMETER_PIN = A0;//Control the contrast of the LCD.
int LDR_PIN           = A1;//Auto-brightness option.

void setup()
{  
  CONNECTIONS();//Function responsible for the connections of the component to Arduino.
  LCD_STARTUP();//Function initiating the LCD and printing "ARDUINO CAR GAME".
}

void loop()
{  
  GAME_SETTINGS();//Function responsible for all settings of the game.
}

void CONNECTIONS()
{
  //OUTPUT PINS.
  pinMode(PIEZO,OUTPUT);
  pinMode(CONTRAST_PIN,OUTPUT);
  
  //INPUT PINS.
  pinMode(PUSHBUTTON,INPUT);
  pinMode(SLIDESWITCH,INPUT);
  pinMode(LDR_PIN,INPUT);
  pinMode(POTENTIOMETER_PIN,INPUT);
}

void LCD_STARTUP()
{  
  lcd.begin(NB_OF_COULOUMS,NB_OF_ROWS);//Initialize LCD screen.
  lcd.print("ARDUINO CAR GAME");       //Print "ARDUINO CAR GAME".
  delay(1000);                         //Wait 1 second.
  lcd.clear();                         //Clear the screen
}

void GAME_SETTINGS()
{
  
  while(true)
  { 
    int START    = digitalRead(PUSHBUTTON) ;//Variable saving the state of pushbutton pin.
    int CONTROL = digitalRead(SLIDESWITCH) ;//Variable saving the state of slide switch pin.
    
    LCD_BRIGHTNESS();//Function responsible for brightness control.
    
    lcd.setCursor(1,0);
    lcd.print("Press To Start");//print "Press To Start" at coordinate(1,0).
    
    lcd.setCursor(6,1);//print loadingstarting from coordinate (6,1).
    lcd.print(".");
    delay(250);
    lcd.setCursor(6,1);
    lcd.print(" ");
    lcd.setCursor(7,1);
    lcd.print(".");
    delay(250);
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(8,1);
    lcd.print(".");
    delay(250);
    lcd.setCursor(8,1);
    lcd.print(" ");
    delay(250);
    
    if(START == 1)//If the pushbutton is pressed, the game will start.
     {
       lcd.clear();//Clear the LCD screen.
      
       while(true)//Print the obsticales and the car position.
       {
         OBSTICALES(35,15,21,35);
         OBSTICALES(35,11,18,35);
         OBSTICALES(35,07,15,35);
         OBSTICALES(35,03,11,35);
         OBSTICALES(15,35,07,35);
         OBSTICALES(11,35,03,35);
         
         OBSTICALES(07,21,15,35);
         OBSTICALES(03,18,11,35);
         OBSTICALES(35,15,07,35);
         OBSTICALES(35,11,03,35);
         OBSTICALES(35,07,35,15);
         OBSTICALES(35,03,35,11);
         
         OBSTICALES(15,18,24,07);       
         OBSTICALES(11,15,21,03);
         OBSTICALES(07,11,18,35);
         OBSTICALES(03,07,15,35);
         OBSTICALES(35,03,11,35);
         OBSTICALES(15,35,07,35);
         OBSTICALES(11,35,03,35);
         
         OBSTICALES(07,24,18,15);
         OBSTICALES(03,21,15,11);
         OBSTICALES(35,18,11,07);
         OBSTICALES(35,15,07,03);
         OBSTICALES(35,11,03,35);
         OBSTICALES(35,07,35,35);
         OBSTICALES(35,03,35,35);
       }
     }
  } 
}

void OBSTICALES(int a,int b,int c,int d)//Function responsible for printing the objects blocking the car way.
{ 
  //we define 4 variables a&b for obsticales 1&2 at row 0, and c&d for obsticales 3&4 at row 1.
  
  int CONTROL = digitalRead(SLIDESWITCH);
  
  CONTROLLER_SWITCH();
  lcd.setCursor(a,0);
  lcd.print("*");
  lcd.setCursor(b,0);
  lcd.print("*");
  lcd.setCursor(c,1);
  lcd.print("*");
  lcd.setCursor(d,1);
  lcd.print("*");
  
  delay(TIME);
  
  CONTROLLER_SWITCH();
  lcd.setCursor(a,0);
  lcd.print(" ");
  lcd.setCursor(a-1,0);
  lcd.print("*");
  lcd.setCursor(b,0);  
  lcd.print(" ");
  lcd.setCursor(b-1,0);
  lcd.print("*");
  lcd.setCursor(c,1);
  lcd.print(" ");
  lcd.setCursor(c-1,1);
  lcd.print("*");
  lcd.setCursor(d,1);  
  lcd.print(" ");
  lcd.setCursor(d-1,1);
  lcd.print("*");
  
  delay(TIME);
  
  CONTROLLER_SWITCH();
  lcd.setCursor(a-1,0);
  lcd.print(" ");
  lcd.setCursor(a-2,0);
  lcd.print("*");
  lcd.setCursor(b-1,0);  
  lcd.print(" ");
  lcd.setCursor(b-2,0);
  lcd.print("*");
  lcd.setCursor(c-1,1);
  lcd.print(" ");
  lcd.setCursor(c-2,1);
  lcd.print("*");
  lcd.setCursor(d-1,1);  
  lcd.print(" ");
  lcd.setCursor(d-2,1);
  lcd.print("*");
  
  delay(TIME);
  
  CONTROLLER_SWITCH();
  lcd.setCursor(a-2,0);
  lcd.print(" ");
  lcd.setCursor(b-2,0);  
  lcd.print(" ");
  lcd.setCursor(c-2,1);
  lcd.print(" ");
  lcd.setCursor(d-2,1);  
  lcd.print(" ");
  lcd.setCursor(a-3,0);
  lcd.print("*");
  lcd.setCursor(b-3,0);
  lcd.print("*");
  lcd.setCursor(c-3,1);
  lcd.print("*");
  lcd.setCursor(d-3,1);
  lcd.print("*");
  
  delay(TIME);
  
  CONTROLLER_SWITCH();
  lcd.setCursor(a-3,0);
  lcd.print(" ");
  lcd.setCursor(b-3,0);
  lcd.print(" ");
  lcd.setCursor(c-3,1);
  lcd.print(" ");
  lcd.setCursor(d-3,1);
  lcd.print(" ");
  
  if(CONTROL == 0 && (a-3 == 0 || b-3 == 0) )//If the car at row 0,and object 1 or 2 is at position 0 the game will end.
    {
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("Game");
      lcd.setCursor(8,1);
      lcd.print("Over");
      tone(3,250,1000);
      delay(1000);
      lcd.clear();
      GAME_SETTINGS();
    }
  
  else if(CONTROL == 1 && (c-3 == 0 || d-3 == 0) )//Similar to the first if statement but for row 1.
    {
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("Game");
      lcd.setCursor(8,1);
      lcd.print("Over");
      tone(3,250,1000);
      delay(1000);
      lcd.clear();
      GAME_SETTINGS();
    }
  
} 

void CONTROLLER_SWITCH()//Function responsible for positioning the car.
{
  int CONTROL = digitalRead(SLIDESWITCH);
  
  switch(CONTROL)
  {
    //If the state of the switch is 0,then print the ">" on row 0.
    case 0:lcd.setCursor(0,0);
           lcd.print(">");
           lcd.setCursor(0,1);
           lcd.print(" ");
           break;
    
    //If the state of the switch is 1,then print the ">" on row 1.
    case 1:lcd.setCursor(0,0);
           lcd.print(" ");
           lcd.setCursor(0,1);
           lcd.print(">");
           break;
  }
}

void LCD_BRIGHTNESS()//Function responsible for the control of the LCD.
{
  int LDR           = analogRead(LDR_PIN);
  int POTENTIOMETER = analogRead(POTENTIOMETER_PIN);
  
  if(POTENTIOMETER == 0)//If potentiometer pin reads 0, the LDR will be acticated.
    { 
      if     (LDR<=100) analogWrite(CONTRAST_PIN,225);
      else if(LDR<=200) analogWrite(CONTRAST_PIN,200);
      else if(LDR<=780) analogWrite(CONTRAST_PIN,175);
      else if(LDR<=890) analogWrite(CONTRAST_PIN,150);
      else if(LDR<=910) analogWrite(CONTRAST_PIN,125);
      else if(LDR<=930) analogWrite(CONTRAST_PIN,100);
      else if(LDR<=940) analogWrite(CONTRAST_PIN,75);
      else if(LDR<=950) analogWrite(CONTRAST_PIN,50);
      else if(LDR<=960) analogWrite(CONTRAST_PIN,25);  
      else              analogWrite(CONTRAST_PIN,0);
    }
  
  //Once the potentiometer pin reads >0,the contrast is controlled by it.
  else if(POTENTIOMETER<=100) analogWrite(CONTRAST_PIN,255);
  else if(POTENTIOMETER<=200) analogWrite(CONTRAST_PIN,200);
  else if(POTENTIOMETER<=300) analogWrite(CONTRAST_PIN,175);
  else if(POTENTIOMETER<=400) analogWrite(CONTRAST_PIN,150);
  else if(POTENTIOMETER<=500) analogWrite(CONTRAST_PIN,125);
  else if(POTENTIOMETER<=600) analogWrite(CONTRAST_PIN,100);
  else if(POTENTIOMETER<=700) analogWrite(CONTRAST_PIN,75);
  else if(POTENTIOMETER<=800) analogWrite(CONTRAST_PIN,50);  
  else                        analogWrite(CONTRAST_PIN,0);

}
