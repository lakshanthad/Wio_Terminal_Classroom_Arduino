#include "TFT_eSPI.h" //include TFT LCD library 

TFT_eSPI tft; //initialize TFT LCD

#define LCD_BACKLIGHT (72Ul) //set control pin of LCD backlight 

void setup() {
  pinMode(WIO_LIGHT, INPUT); //set light sensor pin as INPUT 

  tft.begin(); //start TFT LCD
  digitalWrite(LCD_BACKLIGHT, LOW); //turn off LCD backlight

}

void loop() {
  if (analogRead(WIO_LIGHT) < 200){ //check whether light sensor reading is below 200
    digitalWrite(LCD_BACKLIGHT, HIGH); //turn on LCD backlight 
    tft.fillScreen(TFT_WHITE); //fill background 
  }
  else{
    digitalWrite(LCD_BACKLIGHT, LOW); //turn off LCD backlight 
  }
}
