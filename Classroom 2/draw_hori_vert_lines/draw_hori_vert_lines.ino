#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_YELLOW); //fill background 
  tft.drawFastHLine(0,100,320,TFT_BLACK); //draw horizontal line 
  tft.drawFastVLine(150,0,240,TFT_BLACK); //draw vertical line 
}

void loop() {
  // put your main code here, to run repeatedly:

}
