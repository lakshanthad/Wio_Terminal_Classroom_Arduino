#include "TFT_eSPI.h" //include TFT LCD 

TFT_eSPI tft; //initialize TFT LCD 

TFT_eSprite spr = TFT_eSprite(&tft); //initialize buffer 

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
  pinMode(WIO_KEY_A, INPUT); //set button A pin as input 
  pinMode(WIO_KEY_B, INPUT); //set button B pin as input 
  pinMode(WIO_KEY_C, INPUT); //set button C pin as input 
}
 
void loop() {
  tft.setTextSize(4); //set text size 
  tft.setTextColor(TFT_YELLOW); //set text color
  
  if (digitalRead(WIO_KEY_A) == LOW) { //check whether button A is pressed
   tft.drawString("A is pressed",15,110); //display text string if above condition is met 
   delay(1000); //hold text on screen 
  }
  else if (digitalRead(WIO_KEY_B) == LOW) {
   tft.drawString("B is pressed",15,110);
   delay(1000);
  }
  else if (digitalRead(WIO_KEY_C) == LOW) {
   tft.drawString("C is pressed",15,110);
   delay(1000);
  }
  
  spr.pushSprite(0,0); //push to LCD
  delay(200);
}
