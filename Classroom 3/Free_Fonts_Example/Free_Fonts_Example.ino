#include "TFT_eSPI.h" //include TFT LCD library 
#include "Free_Fonts.h" //include free fonts library 

TFT_eSPI tft; //initialize TFT LCD

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
  tft.fillScreen(TFT_BLACK); //fill background 

  tft.setFreeFont(&FreeMonoBold9pt7b); //set font type 
  tft.drawString("This is an example",0,0); //draw text string 

  tft.setFreeFont(FF25);
  tft.drawString("This is method 2",0,50);

  tft.setFreeFont(FMB12);
  tft.drawString("This is method 3",0,100);
}

void loop() {

}
