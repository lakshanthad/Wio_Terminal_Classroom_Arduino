//Libraries 
#include "Keyboard.h" //keyboard library
#include "TFT_eSPI.h" //TFT LCD library 

//Initializations
TFT_eSPI tft; //initialize TFT LCD 
TFT_eSprite spr = TFT_eSprite(&tft); //initialize buffer  

void setup() { 
  //set button and switch pins as inputs
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_KEY_C, INPUT);
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
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
  spr.fillRect(0,0,320,50,TFT_PURPLE); //draw rectangle with fill color 
  spr.setTextSize(2); //set text size
  spr.setTextColor(TFT_WHITE); //set text color 
  spr.drawString("VLC MEDIA PLAYER CONTROLS",15,18); //draw a text string 

  //draw shapes 
  spr.drawCircle(60,100,40,TFT_DARKGREEN); //draw circle with border
  spr.drawCircle(60,190,40,TFT_RED);
  spr.drawCircle(260,100,40,TFT_PURPLE);
  spr.drawCircle(260,190,40,TFT_PURPLE);
  spr.drawTriangle(160,70,130,115,190,115,TFT_DARKGREEN); //draw triangle with border
  spr.drawTriangle(160,210,130,165,190,165,TFT_RED);


  //draw text
  spr.setTextSize(2); 
  spr.setTextColor(TFT_BLACK);  
  spr.drawString("PLAY",36,95); 
  spr.drawString("MUTE",36,185); 
  spr.drawString("FULL",238,95);
  spr.drawString("ZOOM",238,185);
  spr.drawString("VOLUME",125,135);
 
  spr.pushSprite(0,0); //push to LCD                    

  //use buttons and switches for keyboard shortcuts in VLC Media Player 
  //play/stop video  
  if (digitalRead(WIO_5S_PRESS) == LOW) { //detect button press
    Keyboard.write(32); //single key pressed (ASCII value 32 for spacebar)
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer
    spr.fillCircle(60,100,40,TFT_DARKGREEN); //draw circle with fill color 
    spr.setTextColor(TFT_WHITE); 
    spr.drawString("PLAY",36,95); 
    spr.pushSprite(0,0);
    delay(200); 
  }   
  //mute video 
  if (digitalRead(WIO_KEY_C) == LOW) {      
    Keyboard.write('m'); //single key is pressed (character) 
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); 
    spr.fillCircle(60,190,40,TFT_RED); 
    spr.setTextColor(TFT_WHITE); 
    spr.drawString("MUTE",36,185); 
    spr.pushSprite(0,0);
    delay(200);
  }
  //toggle full screen
  if (digitalRead(WIO_KEY_B) == LOW) {   
    Keyboard.write('f'); 
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); 
    spr.fillCircle(260,100,40,TFT_PURPLE); 
    spr.setTextColor(TFT_WHITE); 
    spr.drawString("FULL",238,95); 
    spr.pushSprite(0,0);
    delay(200);
  }  
  //change zoom mode 
  if (digitalRead(WIO_KEY_A) == LOW) {        
    Keyboard.write('z'); 
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); 
    spr.fillCircle(260,190,40,TFT_PURPLE); 
    spr.setTextColor(TFT_WHITE); 
    spr.drawString("ZOOM",238,185);  
    spr.pushSprite(0,0);   
    delay(200);
  } 
  //volume up  
  if (digitalRead(WIO_5S_UP) == LOW) {      
    Keyboard.write(KEY_UP_ARROW); //single key is pressed (modifier key)      
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH);
    spr.fillTriangle(160,70,130,115,190,115,TFT_DARKGREEN); //draw triangle with fill color 
    spr.pushSprite(0,0);   
    delay(200);
  }
  //volume down 
  if (digitalRead(WIO_5S_DOWN) == LOW) {         
    Keyboard.write(KEY_DOWN_ARROW); 
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); 
    spr.fillTriangle(160,210,130,165,190,165,TFT_RED);  
    spr.pushSprite(0,0);      
    delay(200);
  }           

}
