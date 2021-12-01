//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
//LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trig 6
#define echo 7
#define y A1

int M2=4;
int M3=5;


float duration=0;
int distance=0;
int i;
 int pir=A0;

 String serialdata,value1,value2;
void setup()
{

   lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(M2,OUTPUT);
digitalWrite(M2,HIGH);
  pinMode(M3,OUTPUT);
digitalWrite(M3,HIGH);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);

 pinMode(y,INPUT);

 pinMode(pir,INPUT);
 
 


  //lcd.backlight();
  //lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("SMART SHOE ");
   lcd.setCursor(0,1);
  lcd.print("MONITORINGSYSTEM");
  delay(4000);
  lcd.clear();
}


 

 
void loop()
{

if(Serial.available()>0){
    
   serialdata=Serial.readStringUntil('\r');

    //Serial.print(dat);
    delay(250);

for (int i = 0; i < serialdata.length(); i++) {
  if (serialdata.substring(i, i+1) == ",") {
     value1 = serialdata.substring(0, i);
    value2= serialdata.substring(i+1,i+10);
//  Serial.println(value1);
//Serial.println(value2);

  }
}
}


//int x1 = analogRead(x);
int y1 = analogRead(y);
//int z1 = analogRead(z);
lcd.setCursor(0,0);
lcd.print("M:");
lcd.print(y1);


//Serial.println(x1);
//Serial.println(y1);
//Serial.println(z1); 

if(y1>=350)
{
   lcd.setCursor(7,1);
  lcd.print("FALL DET");
   // digitalWrite(8,LOW);
    delay(3000);
    iot1();
   // iot1();
  // lcd.clear(); 
}
else
{
    //digitalWrite(8,HIGH);
}


//ultra();
int pir1= digitalRead(pir);
lcd.setCursor(7,0);
  lcd.print("PIR:");
  lcd.print(pir1);
  
if(pir1==1)
{
  //lcd.clear();
  lcd.setCursor(11,0);
  lcd.print("P DET");
 // i++;
  digitalWrite(M2,LOW);
  delay(3000);
 // lcd.clear();
}
else
{
    digitalWrite(M2,HIGH);
}



//lcd.setCursor(0,0);
//  lcd.print("PIR:");
//  lcd.print(pir1);
  
  
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
duration=pulseIn(echo,HIGH);
distance=duration*0.034/2;
 
  lcd.setCursor(0,1);
 lcd.print("D:");
 lcd.print(distance);
 lcd.print("cm");

 
 delay(1000);
//lcd.clear();

if(distance<15)
{
  lcd.setCursor(7,1);
 lcd.print("OBJ DET");
  digitalWrite(M3,LOW);
  //delay(1000);
 delay(3000);
// lcd.clear();

  
}
else
{
    digitalWrite(M3,HIGH);
}
 lcd.clear();
// delay(1000);
}
void iot1()
{

 Serial.print("{\"data\":{\"s1\":");Serial.print("\"EMERGENCY\",");
  Serial.print("\"s2\":");Serial.print("\"FELL DOWN\"");
  Serial.print(",\"s3\":");Serial.print(value1);
  Serial.print(",\"s4\":");Serial.print(value2);
  Serial.print(",\"s5\":");Serial.print("\"NA\"");
  Serial.print(",\"s6\":");Serial.print("\"NA\"");
  Serial.print(",\"s7\":");Serial.print("\"NA\"");
  Serial.print(",\"s8\":");Serial.print("\"NA\",");
  Serial.print("\"sms\":");Serial.print("\"1\"");
  Serial.println("}}#");delay(5000); 

   
}  
