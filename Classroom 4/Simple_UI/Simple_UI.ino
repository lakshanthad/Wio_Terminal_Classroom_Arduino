#include "TFT_eSPI.h" //include TFT LCD library 
#include "Free_Fonts.h" //include free fonts library 
#include "Seeed_FS.h" //include file system library
#include "RawImage.h" //include raw image library 

TFT_eSPI tft; //initialize TFT LCD

void setup() {
  
  if (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)){ //check whether SD card is inserted and working 
    while(1);
  }

  tft.begin(); //start TFT LCD
  tft.setRotation(3); //set screen rotation 
  tft.fillScreen(TFT_WHITE); //fill background 

  //Drawing for brightness
  tft.setFreeFont(&FreeSansBold12pt7b); //set font type 
  tft.setTextColor(TFT_BLACK); //set text color 
  tft.drawString("Brightness",90,10); //draw text string 

  tft.drawRect(75,45,160,20,TFT_NAVY); //draw rectangle with border
  tft.fillRect(75,45,120,20,TFT_NAVY); //fill rectangle with color 

  tft.fillCircle(35,55,25,TFT_RED); //fill circle with color 
  tft.fillCircle(275,55,25,TFT_DARKGREEN);

  //Drawing for Volume
  tft.setFreeFont(&FreeSerifBoldItalic12pt7b);
  tft.setTextColor(TFT_BLACK);
  tft.drawString("Volume",110,90);

  tft.drawRect(75,120,160,20,TFT_NAVY);
  tft.fillRect(75,120,90,20,TFT_NAVY);

  tft.fillCircle(35,130,25,TFT_RED);
  tft.fillCircle(275,130,25,TFT_DARKGREEN);

  //Drawing Images
  drawImage<uint16_t>("back.bmp",0,180); //display image on LCD
  drawImage<uint16_t>("home.bmp",260,180);

}

void loop() {
  // put your main code here, to run repeatedly:

}
