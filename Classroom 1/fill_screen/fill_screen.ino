#include"TFT_eSPI.h" //include TFT LCD library 

TFT_eSPI tft; //initialize TFT LCD 
 
void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
 
  tft.fillScreen(TFT_RED); //fill background (method 1)
//tft.fillScreen(tft.color565(255,0,0)); //fill background (method 2)

}
 
void loop() {
 
}
