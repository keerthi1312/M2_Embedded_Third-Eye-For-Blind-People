
#ifndef __USER_UTILS_H__
#define __USER_UTILS_H__
/**
 * @file user_utils.h
 * @author Keerthana.A ()
 * @brief User defined utilities used across the project
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"
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
#endif /* __USER_UTILS_H__ */
