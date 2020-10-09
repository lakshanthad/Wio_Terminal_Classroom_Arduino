#include "TFT_eSPI.h" //include TFT LCD 
#include "Seeed_FS.h" //include file system library 
#include "RawImage.h" //include raw image library

TFT_eSPI tft; //initialize TFT LCD 

void setup() {
  if(!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)) { //check whether SD card is inserted and working 
        while(1);
    }
    
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation 
  pinMode(WIO_KEY_A, INPUT); //set button A pin as input
  pinMode(WIO_KEY_B, INPUT); //set button B pin as input
  pinMode(WIO_KEY_C, INPUT); //set button C pin as input
}
 
void loop() {
   if (digitalRead(WIO_KEY_A) == LOW) { //check whether button A is pressed
    drawImage<uint16_t>("1.bmp",0,0); //display image if above condition is met
   }
   else if (digitalRead(WIO_KEY_B) == LOW) {
    drawImage<uint16_t>("2.bmp",0,0);
   }
   else if (digitalRead(WIO_KEY_C) == LOW) {
    drawImage<uint16_t>("3.bmp",0,0);
   }

}
