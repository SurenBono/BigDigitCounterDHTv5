//https://maxpromer.github.io/LCD-Character-Creator/
//https://robojax.com/learn/arduino/?vid=robojax-DHT11_simple

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <dht11.h>
dht11 DHT11; 
#define dhtpin A0 

float T;
float H;

LiquidCrystal_I2C lcd(0x27, 20, 4);

int num,num1,num2,num3,num4,num5,counter;
bool semicol = true;

void setup() {lcd.begin();lcdcharinitiate();}

void loop() {
	
for (int l = 0; l < 5; l++) {lcddisplay();}
      	
 th5();
}


void lcddisplay() {
  
   
lcd.setCursor(0,0);
lcd.print("------I2C LCD------");  
H = DHT11.humidity;T = DHT11.temperature;
lcd.setCursor(0,1);lcd.print("T: ");lcd.print(T,1);lcd.print((char)223);lcd.print("C");
lcd.setCursor(11,1);lcd.print("H: ");lcd.print(H,1);lcd.print("%");
counter++;
big_digit(); 
delay(1000);
lcd.clear(); 
}

void th5() {
  
DHT11.read(dhtpin);    
lcd.setCursor(0,0);
lcd.print("------I2C LCD------");  
H = DHT11.humidity;T = DHT11.temperature;
lcd.setCursor(0,1);lcd.print("T: ");lcd.print(T,1);lcd.print((char)223);lcd.print("C");
lcd.setCursor(11,1);lcd.print("H: ");lcd.print(H,1);lcd.print("%");
counter++;
big_digit(); 
delay(1000);
lcd.clear(); 
}
  
void lcdcharinitiate(){
  
    byte C0[8] = {0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00};
    byte C1[8] = {0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00};
    byte C2[8] = {0x1F,0x1F,0x00,0x00,0x00,0x00,0x1F,0x1F};
    byte C3[8] = {0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07};
    byte C4[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x07};
    byte C5[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x1F};
    byte C6[8] = {0x07,0x07,0x00,0x00,0x00,0x00,0x07,0x07};
    byte C7[8] = {0x00,0x00,0x0F,0x09,0x09,0x0F,0x00,0x00};
    
    lcd.createChar(0 , C0);
    lcd.createChar(1 , C1);
    lcd.createChar(2 , C2);
    lcd.createChar(3 , C3);
    lcd.createChar(4 , C4);
    lcd.createChar(5 , C5);
    lcd.createChar(6 , C6);
    lcd.createChar(7 , C7);  
}

void big_digit(){
	
semicol=!semicol;  
num++;
if (num>9){num=0;num1++;}
if (num1>5){num1=0;num2++;}
if (num2>9){num2=0;num3++;}
if (num3>5){num3=0;num4++;}
if (num4>9){num4=0;num5++;}
if (num5>9){num5=0;num5++;}
numberprinter(num,17);
numberprinter(num1,14);
numberprinter(num2,10);
numberprinter(num3,7);
numberprinter(num4,3);
numberprinter(num5,0);

if(semicol)
{lcdnumbersemicolon(6); lcdnumbersemicolonoff(13);}else
{lcdnumbersemicolonoff(6);lcdnumbersemicolon(13);}
}

void numberprinter(int num , int pos)
{
  if(num == 0){ lcdnumber0(pos);}
  if(num == 1){lcdnumber1(pos);}
  if(num == 2){lcdnumber2(pos);}
  if(num == 3){lcdnumber3(pos);}
  if(num == 4){lcdnumber4(pos);}
  if(num == 5){lcdnumber5(pos);}
  if(num == 6){lcdnumber6(pos);}
  if(num == 7){lcdnumber7(pos);}
  if(num == 8){lcdnumber8(pos);}
  if(num == 9){lcdnumber9(pos);}
  if(num == 10){lcdnumber10(pos);}
  if(num == 11){lcdnumber11(pos);}
}

void lcdnumber0(int startposition)
{
    lcd.setCursor(startposition+0,2);
    lcd.write((byte)3); 
	  lcd.write((byte)1); 
	  lcd.write((byte)255);
    lcd.setCursor(startposition+0,3);
    lcd.write((byte)3); 
	  lcd.write((byte)5); 
	  lcd.write((byte)255);
}
void lcdnumber1(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)0);
	lcd.write((byte)255);
	lcd.print(" ");
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)4);
	lcd.write((byte)255);
	lcd.write((byte)5);
}
void lcdnumber2(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)6);
	lcd.write((byte)2);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)3);
	lcd.write((byte)5);
	lcd.write((byte)5);
}
void lcdnumber3(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)0);
	lcd.write((byte)2);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)4);
	lcd.write((byte)5);
	lcd.write((byte)255);
}
void lcdnumber4(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)3);
	lcd.write((byte)5);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.print(" ");
	lcd.print(" ");
	lcd.write((byte)255);
}
void lcdnumber5(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)3);
	lcd.write((byte)2);
	lcd.write((byte)2);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)4);
	lcd.write((byte)5);
	lcd.write((byte)255);
}
void lcdnumber6(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)3);
	lcd.write((byte)2);
	lcd.write((byte)2);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)3);
	lcd.write((byte)5);
	lcd.write((byte)255);
}
void lcdnumber7(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)0);
	lcd.write((byte)1);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.print((char)254);
	lcd.write((char)254);
	lcd.write((byte)255);
}
void lcdnumber8(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)3);
	lcd.write((byte)2);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)3);
	lcd.write((byte)5);
	lcd.write((byte)255);
}
void lcdnumber9(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)3);
	lcd.write((byte)2);
	lcd.write((byte)255);
  lcd.setCursor(startposition+0,3);
  lcd.print((char)254);
	lcd.print((char)254);
	lcd.write(255);
}
void lcdnumber10(int startposition) // if hr2 zero dont display anything until 1
{
  lcd.setCursor(startposition+0,2);
  lcd.write((char)254);
  lcd.write((char)254);
  lcd.write((char)254);
  lcd.setCursor(startposition+0,3);
  lcd.print((char)254);
  lcd.print((char)254);
  lcd.write((char)254);
}
void lcdnumber11(int startposition)   // integer 11=1 alter byte
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)0);
  lcd.write((byte)255);
  lcd.print(" ");
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)4);
  lcd.write((byte)255);
  lcd.write((byte)5);
}
void lcdnumbersemicolon(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)161);//165
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)219);//165
}
void lcdnumbersemicolonoff(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write((byte)219);//((byte)254);
  lcd.setCursor(startposition+0,3);
  lcd.write((byte)161);//((byte)254);
}
void lcdam(int startposition)
{
  lcd.setCursor(startposition+0,2);
  lcd.write("AM");
}
void lcdpm(int startposition)
{
  lcd.setCursor(startposition+0,3);
  lcd.write("PM");
}
