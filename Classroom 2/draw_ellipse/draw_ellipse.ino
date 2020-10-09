#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_YELLOW); //fill background 
  tft.drawEllipse(100,100,40,70,TFT_BLACK); //draw ellipse with border
}

void loop() {
  // put your main code here, to run repeatedly:

}
