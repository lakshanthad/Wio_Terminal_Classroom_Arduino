#include "Wire.h" //include wire library 
#include "rgb_lcd.h" //include 16X2 LCD library

rgb_lcd lcd; //initialize RGB LCD 

void setup() {
  lcd.begin(16,2); //start 16x2 LCD
  
  lcd.print("hello world!"); //print text on LCD
}

void loop() {

}
