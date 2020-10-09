#include "Histogram.h" //include histogram library 

TFT_Histogram histogram = TFT_Histogram(); //initialize histogram
TFT_eSPI tft; //initialize TFT LCD

void setup() {
  tft.begin(); //start TFT LCD 
  histogram.initHistogram(&tft); //start histogram

  histogram.formHistogram("a",1,60,30,TFT_BLUE); //draw histogram column (string label, tag number, height, width, color)
  histogram.formHistogram("b",2,30,40,TFT_RED);
  histogram.formHistogram("c",3,90,40,TFT_YELLOW);
  histogram.formHistogram("d",4,70,50,TFT_GREEN);
  histogram.formHistogram("e",5,130,40,TFT_ORANGE);
  histogram.formHistogram("f",6,120,30,TFT_BLACK);
  histogram.formHistogram("g",7,50,40,TFT_PINK);

  histogram.showHistogram(); //display histogram 
  delay(3000); //display for 3 seconds 

  histogram.changeParam(5,"E",55,TFT_RED); //change histogram column of tag number 5
  histogram.deleteCylinder(4); //delete histogram column referring to tag number 
  histogram.lineChart(TFT_BLACK); //add line chart over histogram 
  delay(3000);
  
  histogram.notShowAxis(); //hide histogram axis 
}

void loop() {

}
