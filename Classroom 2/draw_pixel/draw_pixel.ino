#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_YELLOW); //fill background 
  tft.drawPixel(10,10,TFT_BLACK); //draw pixel 

}

void loop() {
  // put your main code here, to run repeatedly:

}
