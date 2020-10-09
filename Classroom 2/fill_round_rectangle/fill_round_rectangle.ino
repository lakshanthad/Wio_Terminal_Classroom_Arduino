#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_YELLOW); //fill background 
  tft.fillRoundRect(100,100,80,90,10,TFT_RED); //fill round corner rectangle
}

void loop() {
  // put your main code here, to run repeatedly:

}
