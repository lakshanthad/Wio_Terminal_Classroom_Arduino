#include "ADXL335.h" //include accelerometer library
#include "seeed_line_chart.h" //include line chart library 

TFT_eSPI tft; //TFT LCD initialization
ADXL335 accelerometer; //accelerometer initialization
 
#define max_size 50 //maximum size of data
doubles accelerator_readings[3]; //array to store accelerometer values in x,y,z directions
TFT_eSprite spr = TFT_eSprite(&tft); //create buffer
 
void setup() {
  tft.begin(); //start TFT LCD  
  tft.setRotation(3); //set screen rotation
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 

  accelerometer.begin(); //start accelerometer 
}
 
void loop() {
  spr.fillSprite(TFT_WHITE); //fill background 

  float ax = accelerometer.getAccelerationX(); //create variable to store x-axis accelerometer values
  float ay = accelerometer.getAccelerationY(); //create variable to store y-axis accelerometer values
  float az = accelerometer.getAccelerationZ(); //create variable to store z-axis accelerometer values
 
  if (accelerator_readings[0].size() == max_size) {
    for (uint8_t i = 0; i<3; i++){
      accelerator_readings[i].pop(); //Used to remove the first read variable
    }
  }
  accelerator_readings[0].push(ax); //store x-axis accelerometer values in array
  accelerator_readings[1].push(ay); //store y-axis accelerometer values in array
  accelerator_readings[2].push(az); //store z-axis accelerometer values in array
 
  //Settings for the line graph title
  auto header = text(0, 0); //starting coordinates of text 
  header.value("Acceleration Readings"); //text string 
  header.align(center); //horizontal alignment
  header.valign(vcenter); //vertical alignment 
  header.width(tft.width()); //width of title header 
  header.thickness(2); //font size 
  header.height(header.font_height() * 2); //height of title header
  header.draw(); //Header height is twice the height of the font
 
  //Settings for the line graph
  auto content = line_chart(20, header.height()); //(x,y) where the line graph begins
  content.height(tft.height() - header.height() * 1.5); //actual height of the line chart
  content.width(tft.width() - content.x() * 2); //actual width of the line chart
  content.based_on(-2.0); //Starting point of y-axis, must be a float
  content.show_circle(false); //drawing a cirle at each point, default is on.
  content.value({accelerator_readings[0],accelerator_readings[1], accelerator_readings[2]}); //passing through the data to line graph
  content.color(TFT_BLUE, TFT_RED, TFT_GREEN); //setting line graph colors
  content.draw(); //draw line graph 
 
  spr.pushSprite(0, 0); //push to LCD
  delay(50);
}
