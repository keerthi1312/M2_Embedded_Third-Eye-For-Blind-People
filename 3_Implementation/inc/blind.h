/**
 * @file blind.h
 * @author Keerthana.A ()
 * @brief Project to Blind an LED connected to AVR328 MCU GPIO Pin
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define trig 6
#define echo 7
#define y A1
