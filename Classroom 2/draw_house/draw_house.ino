#include "TFT_eSPI.h" //include TFT LCD library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  tft.fillScreen(TFT_BLACK); //fill background 
  tft.fillRect(60,110,200,120,TFT_YELLOW); //fill rectangle with color
  tft.fillTriangle(160,10,60,110,260,110,TFT_RED); //fill triangle with color 
  tft.fillRect(140,150,40,80,TFT_ORANGE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
