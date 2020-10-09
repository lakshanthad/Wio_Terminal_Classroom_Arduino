#include "TFT_eSPI.h" //include TFT LCD library 
#include "Seeed_FS.h" //include file system library 
#include "RawImage.h" //include raw image library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  if (!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)){ //check whether SD card is inserted and working 
    while(1);
  }
  
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 

  drawImage<uint16_t>("logo.bmp",0,0); //display image on LCD

}

void loop() {

}
