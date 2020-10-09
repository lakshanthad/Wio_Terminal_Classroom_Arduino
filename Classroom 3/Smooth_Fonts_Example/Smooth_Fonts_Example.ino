#include "TFT_eSPI.h" //include TFT LCD library 
#include "Seeed_FS.h" //include file system library 
#include "SD/Seeed_SD.h" //include SD card library 

TFT_eSPI tft; //initialize TFT LCD 
 
void setup() {
  tft.begin(); //start TFT LCD 
  tft.setRotation(3); //set screen rotation
  tft.fillScreen(TFT_BLACK); //fill background 

  Serial.begin(115200); //start serial communication 
 
  while(!SD.begin(SDCARD_SS_PIN, SDCARD_SPI)){ //check whether SD card is inserted and working 
      Serial.println("SD card error!\n"); 
      while(1);
  }
  delay(1000);
 
  tft.loadFont("Cambria-20"); //load font to Wio Terminal from SD card 
  // Show all characters on screen with 2 second (2000ms) delay between screens
  tft.showFont(2000); // Note: This function moves the cursor position!
 
  tft.setTextColor(TFT_RED); //set Text color 
  tft.setCursor(0,0); //set cursor position 
 
  tft.println("This is a smooth font"); //print text on LCD 
  tft.println("This is the second line");
  
 
}

void loop(){
  
}
