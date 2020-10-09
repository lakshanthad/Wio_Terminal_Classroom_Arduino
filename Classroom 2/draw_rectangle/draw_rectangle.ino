#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_YELLOW); //fill background 
  tft.drawRect(100,100,100,100,TFT_BLACK); //draw rectangle with border 
}

void loop() {
  // put your main code here, to run repeatedly:

}
