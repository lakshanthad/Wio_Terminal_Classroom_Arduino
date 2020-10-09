#include"seeed_line_chart.h" //include the library
TFT_eSPI tft;
 
#define max_size 50 //maximum size of data
doubles data; //Initializing a doubles type to store data
TFT_eSprite spr = TFT_eSprite(&tft); //create buffer 
 
void setup() {
  tft.begin(); //start TFT LCD  
  tft.setRotation(3); //set screen rotation
  spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
}
 
void loop() {
  spr.fillSprite(TFT_WHITE); //fill background 
  
  if (data.size() == max_size) {
      data.pop();//Used to remove the first read variable
  }
  data.push(random(1, 10)); //generate random values and store in data
 
  //Settings for the line graph title
  auto header = text(0, 0); //fill background 
  header.value("Test Chart"); //text string 
  header.align(center); //horizontal alignment
  header.valign(vcenter); //vertical alignment 
  header.width(tft.width()); //width of title header 
  header.thickness(3); //font size 
  header.height(header.font_height() * 2); //height of title header
  header.draw(); //Header height is twice the height of the font
 
  //Settings for the line graph
  auto content = line_chart(20, header.height()); //(x,y) where the line graph begins
  content.height(tft.height() - header.height() * 1.5); //actual height of the line chart
  content.width(tft.width() - content.x() * 2); //actual width of the line chart
  content.based_on(0.0); //Starting point of y-axis, must be a float
  content.show_circle(false); //drawing a cirle at each point, default is on.
  content.value(data); //passing through the data to line graph
  content.color(TFT_RED); //Setting the color for the line
  content.draw(); //draw line chart 
 
  spr.pushSprite(0, 0); //push to LCD
  delay(50);
}
