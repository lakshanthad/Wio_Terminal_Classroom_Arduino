#include "IRremote.h" //IR remote library
#include "TFT_eSPI.h" //TFT LCD library

TFT_eSPI tft; //Initializing TFT LCD library

TFT_eSprite spr = TFT_eSprite(&tft); //Initializing the buffer

IRsend irsend; //Initializing IR Emitter

//raw data arrays 

unsigned int  POWER[71] = {9050,4500, 550,550, 600,550, 550,550, 600,550, 550,550, 600,550, 550,550, 600,550, 550,1700, 550,1700, 550,1700, 600,1650, 550,1700, 600,1650, 600,500, 600,1650, 600,1650, 600,550, 600,1650, 600,1650, 600,500, 600,550, 600,500, 600,550, 600,550, 550,1700, 550,550, 600,550, 550,1700, 550,1700, 550,1700, 550,1700, 550,41050, 9050,2250, 600};

unsigned int  MUTE[71] = {9050,4500, 550,550, 600,550, 550,550, 600,550, 550,550, 600,550, 550,550, 600,550, 550,1700, 600,1650, 550,1700, 600,1650, 600,1650, 600,1650, 600,500, 600,1650, 600,550, 600,1650, 600,1650, 600,1650, 600,500, 600,550, 600,500, 600,550, 600,1650, 600,500, 600,550, 600,500, 600,1650, 600,1700, 550,1700, 550,1700, 550,41050, 9050,2250, 600};

unsigned int  VOLUP[71] = {9050,4450, 600,550, 600,550, 550,550, 600,550, 550,550, 600,550, 550,550, 600,550, 600,1650, 600,1650, 550,1700, 600,1650, 600,1650, 600,1650, 600,500, 600,1650, 600,550, 600,500, 600,1650, 600,550, 600,500, 600,550, 600,1650, 600,500, 600,1650, 600,1650, 600,550, 600,1650, 600,1650, 600,1650, 600,500, 600,1650, 600,41350, 9050,2250, 550};

unsigned int  VOLDOWN[71] = {9050,4500, 600,550, 550,550, 600,550, 550,550, 600,550, 600,500, 600,550, 550,550, 600,1650, 600,1650, 600,1650, 600,1650, 600,1650, 600,1650, 600,550, 600,1650, 600,1650, 600,1650, 600,500, 600,550, 600,500, 600,550, 600,1650, 600,500, 600,550, 600,500, 600,1650, 600,1650, 600,1650, 600,1700, 550,550, 600,1650, 600,41050, 9050,2200, 600};

unsigned int  CHUP[71] = {9100,4450, 600,550, 600,500, 600,550, 600,500, 600,550, 550,550, 600,550, 550,550, 600,1650, 600,1650, 600,1700, 550,1700, 550,1700, 550,1700, 550,550, 550,1700, 600,550, 550,550, 600,550, 550,1700, 550,1700, 550,550, 600,550, 550,550, 600,1650, 600,1650, 600,1650, 600,550, 550,550, 600,1650, 600,1650, 600,1650, 600,41050, 9050,2250, 600};

unsigned int  CHDOWN[71] = {9050,4500, 600,500, 600,550, 600,500, 600,550, 600,500, 600,550, 600,500, 600,550, 600,1650, 600,1650, 600,1650, 600,1650, 600,1650, 600,1650, 600,550, 550,1700, 550,1700, 550,550, 600,550, 550,1700, 550,1700, 550,550, 600,550, 550,550, 600,550, 550,1700, 550,1700, 550,550, 600,550, 600,1650, 600,1650, 600,1650, 600,41150, 9050,2250, 600};


void setup() {
  //Configuring the buttons and the 5-way switch as inputs
  pinMode(WIO_KEY_A, INPUT);
  pinMode(WIO_KEY_B, INPUT);
  pinMode(WIO_5S_UP, INPUT);
  pinMode(WIO_5S_DOWN, INPUT);
  pinMode(WIO_5S_LEFT, INPUT);
  pinMode(WIO_5S_RIGHT, INPUT);

  tft.begin(); //LCD initialization
  tft.setRotation(3); //Setting LCD rotation
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //Creating the buffer

  spr.fillSprite(TFT_WHITE); //Setting Background color

  //Creating "TV Remote" title
  spr.fillRect(0,0,320,45,TFT_BLUE); //Drawing rectangle with blue fill
  spr.setTextSize(3); //Setting text size 
  spr.setTextColor(TFT_WHITE); //Setting text color
  spr.drawString("TV Remote",80,10); //Drawing text string

  //Draw power button 
  spr.setTextSize(2);
  spr.setTextColor(TFT_BLACK);
  spr.drawCircle(57,90,40,TFT_RED); //Drawing circle with red outline
  spr.drawString("POWER",30,85);

  //Draw mute button 
  spr.drawCircle(57,180,40,TFT_BLUE);
  spr.drawString("MUTE",35,175);

  //Draw verticle line 
  spr.drawFastVLine(115,0,240,TFT_BLUE); 

  //Draw channel buttons 
  spr.setTextSize(3);
  spr.drawString("CH",155,125);
  spr.drawCircle(173,85,25,TFT_DARKGREEN);
  spr.drawCircle(173,185,25,TFT_RED);

  //Draw volume buttons 
  spr.drawString("VOL",230,125);
  spr.drawCircle(250,85,25,TFT_DARKGREEN);
  spr.drawCircle(250,185,25,TFT_RED);

  

}

void loop() {
  //power button 
  if (digitalRead(WIO_KEY_A) == LOW){ //Detecting the button press
    irsend.sendRaw(POWER,71,38); //Pass the array, array length, carrier frequency
    tft.fillCircle(57,90,40,TFT_RED); //Fill circle with red color
    delay(1000);
  }
  //mute button 
  else if(digitalRead(WIO_KEY_B) == LOW){
    irsend.sendRaw(MUTE,71,38);
    tft.fillCircle(57,180,40,TFT_BLUE);
    delay(1000);
  }
  //volume up switch
  else if(digitalRead(WIO_5S_UP) == LOW){
    irsend.sendRaw(VOLUP,71,38);
    tft.fillCircle(250,85,25,TFT_DARKGREEN);
    delay(1000);
  }
  //volume down switch 
  else if(digitalRead(WIO_5S_DOWN) == LOW){
    irsend.sendRaw(VOLDOWN,71,38);
    tft.fillCircle(250,185,25,TFT_RED);
    delay(1000);
  }
  //channel up switch 
  else if(digitalRead(WIO_5S_RIGHT) == LOW){
    irsend.sendRaw(CHUP,71,38);
    tft.fillCircle(173,85,25,TFT_DARKGREEN);
    delay(1000);
  }
  //channel down switch
  else if(digitalRead(WIO_5S_LEFT) == LOW){
    irsend.sendRaw(CHDOWN,71,38);
    tft.fillCircle(173,185,25,TFT_RED);
    delay(1000);
  }

  spr.pushSprite(0,0); //Push to LCD
  delay(50);


}
