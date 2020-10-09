//Libraries 
#include "Keyboard.h" //keyboard library 
#include "TFT_eSPI.h" //TFT LCD library

//Initializations
TFT_eSPI tft; //initialize TFT LCD
TFT_eSprite spr = TFT_eSprite(&tft); //initialize buffer

void setup() {
  //set buttons and switch pins as inputs 
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);
  pinMode(WIO_5S_PRESS, INPUT);

  Keyboard.begin(); //start keyboard communication

  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set TFT LCD rotation

}

void loop() {
  //Drawing UI on TFT LCD 
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
  spr.fillSprite(TFT_WHITE); //set background color 

  //Draw header title 
  spr.fillRect(0,0,320,50,TFT_YELLOW); //draw rectangle with fill color 
  spr.setTextSize(2); //set text size
  spr.setTextColor(TFT_BLACK); //set text color 
  spr.drawString("FILE EXPLORER CONTROLS",23,18); //draw a text string

  //Draw shapes 
  spr.drawCircle(60,100,40,TFT_BLUE); //draw circle with border
  spr.drawCircle(160,100,40,TFT_BLUE);
  spr.drawCircle(260,100,40,TFT_BLUE);
  spr.drawRoundRect(90,160,140,65,10,TFT_DARKGREEN); //draw rounded corner rectangle with border
  
  //Draw text 
  spr.setTextColor(TFT_BLACK);
  spr.drawString("COPY",38,95); //draw a text string 
  spr.drawString("PASTE",133,95);
  spr.drawString("CUT",245,95);
  spr.drawString("NEW FOLDER",100,183);

  spr.pushSprite(0,0); //push to LCD

  //use buttons and switches for keyboard macros in file explorer
  //copy 
  if (digitalRead(WIO_KEY_C) == LOW){ //detect button press
    //Ctrl + 'c' combo for copy
    Keyboard.press(KEY_LEFT_CTRL); //modifier for left ctrl
    Keyboard.press('c'); //single key is pressed
    delay(200); //holding time
    Keyboard.releaseAll(); //release all key presses
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
    spr.fillCircle(60,100,40,TFT_BLUE); //draw a circle with fill color
    spr.setTextColor(TFT_WHITE);
    spr.drawString("COPY",38,95);
    spr.pushSprite(0,0);
    delay(200);   
  }
  //paste 
  if (digitalRead(WIO_KEY_B) == LOW){ //detect button press
    //Ctrl + 'v' combo for paste
    Keyboard.press(KEY_LEFT_CTRL); //modifier for left ctrl
    Keyboard.press('v'); //single key is pressed
    delay(200); //holding time
    Keyboard.releaseAll(); //release all key presses
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
    spr.fillCircle(160,100,40,TFT_BLUE); //draw a circle with fill color
    spr.setTextColor(TFT_WHITE);
    spr.drawString("PASTE",133,95);
    spr.pushSprite(0,0);
    delay(200);   
  }

 //cut
  if (digitalRead(WIO_KEY_A) == LOW){ //detect button press
    //Ctrl + 'x' combo for cut
    Keyboard.press(KEY_LEFT_CTRL); //modifier for left ctrl
    Keyboard.press('x'); //single key is pressed
    delay(200); //holding time
    Keyboard.releaseAll(); //release all key presses
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
    spr.fillCircle(260,100,40,TFT_BLUE); //draw a circle with fill color
    spr.setTextColor(TFT_WHITE);
    spr.drawString("CUT",245,95);
    spr.pushSprite(0,0);
    delay(200);   
  }
  //create new folder
  if (digitalRead(WIO_5S_PRESS) == LOW){ //detect switch press
    //Ctrl + Shift + 'n' combo for new folder
    Keyboard.press(KEY_LEFT_CTRL); //modifier for left ctrl
    Keyboard.press(KEY_LEFT_SHIFT); //modifier for left shift
    Keyboard.press('n'); //single key is pressed
    delay(200); //holding time
    Keyboard.releaseAll(); //release all key presses
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
    spr.fillRoundRect(90,160,140,65,10,TFT_DARKGREEN); //draw rounded corner rectangle with fill color
    spr.setTextColor(TFT_WHITE);
    spr.drawString("NEW FOLDER",100,183);
    spr.pushSprite(0,0);
    delay(200);   
  }

  
  
 
 
  



}
