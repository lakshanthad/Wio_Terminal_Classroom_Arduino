#include "TFT_eSPI.h" //include TFT LCD library 

TFT_eSPI tft; //initialize TFT LCD

TFT_eSprite spr = TFT_eSprite(&tft); //initialize buffer

void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
  pinMode(WIO_5S_UP, INPUT); //set switch pin up as input
  pinMode(WIO_5S_DOWN, INPUT); //set switch pin down as input
  pinMode(WIO_5S_LEFT, INPUT); //set switch pin left as input
  pinMode(WIO_5S_RIGHT, INPUT); //set switch pin right as input
  pinMode(WIO_5S_PRESS, INPUT); //set switch pin press as input
}
 
void loop() {
  tft.setTextSize(6); //set text size
  tft.setTextColor(TFT_RED); //set text color 

  if (digitalRead(WIO_5S_UP) == LOW) { //check whether switch is moved up 
   tft.drawString("UP",130,100); //display text string if above condition is met 
   delay(1000); //hold text on screen 
  }
  else if (digitalRead(WIO_5S_DOWN) == LOW) {
   tft.drawString("DOWN",90,100);
   delay(1000);
  }
  else if (digitalRead(WIO_5S_LEFT) == LOW) {
   tft.drawString("LEFT",90,100);
   delay(1000);
  }
  else if (digitalRead(WIO_5S_RIGHT) == LOW) {
   tft.drawString("RIGHT",90,100);
   delay(1000);
  }
  else if (digitalRead(WIO_5S_PRESS) == LOW) {
   tft.drawString("PRESS",90,100);
   delay(1000);
  }

  spr.pushSprite(0,0); //push to LCD
  delay(200);
}
