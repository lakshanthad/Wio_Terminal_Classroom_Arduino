#include "TFT_eSPI.h" //include TFT LCD library 
 
TFT_eSPI tft; //initialize TFT LCD 

TFT_eSprite spr = TFT_eSprite(&tft); //initialize buffer
 

void setup() {
    pinMode(WIO_MIC, INPUT); //set mic pin as input 
    tft.begin(); //start LCD
    tft.setRotation(3); //set screen rotation
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
}
 
void loop() {
    spr.fillSprite(TFT_BLACK); //fill background 
    tft.setTextSize(5); //set text size
    tft.setTextColor(TFT_RED); //set text color 
    
    if (analogRead(WIO_MIC) > 800){ //condition to check whether analog reading is more than 800
      tft.drawString("TOO LOUD!",30,100); //draw text string if above condition is met 
      delay(2000); //hold text on LCD 
    }

    spr.pushSprite(0, 0); //push to LCD
    delay(50);
}
