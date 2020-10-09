#include"TFT_eSPI.h" //include TFT LCD library 

TFT_eSPI tft; //initialize TFT LCD 
 
void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
 
  tft.fillScreen(TFT_RED); //fill background 

  tft.setTextColor(TFT_BLACK); //set text color
  tft.setTextSize(4); //set text size 
  tft.drawString("Hello world!",0,0); //draw text string 

}
 
void loop() {
 
}
