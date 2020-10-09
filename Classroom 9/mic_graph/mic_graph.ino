#include"seeed_line_chart.h" //include the line chart library
 
TFT_eSPI tft; //TFT LCD initialization
 
#define max_size 50 //maximum size of data
doubles data; //Initializing a doubles type to store data
TFT_eSprite spr = TFT_eSprite(&tft); //create buffer 

void setup() {
    pinMode(WIO_MIC, INPUT); //set mic pin as input 
    
    tft.begin(); //start TFT LCD
    tft.setRotation(3); //set screen rotation
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
}
 
void loop() {
    spr.fillSprite(TFT_WHITE); //fill background 
 
    int val = analogRead(WIO_MIC); //store analog readings from mic 
 
    if (data.size() == max_size) {
        data.pop();//Used to remove the first read variable
    }
    data.push(val); //read variables and store in data
 
    //Settings for the line graph title
    auto header =  text(0, 0) //starting coordinates of text 
                .value("Microphone Reading") //text string 
                .align(center) //horizontal alignment
                .valign(vcenter) //vertical alignment 
                .width(tft.width()) //width of title header 
                .thickness(2); //font size 
 
    header.height(header.font_height() * 2); //height of title header
    header.draw(); //Header height is twice the height of the font
 
  //Settings for the line graph
    auto content = line_chart(20, header.height()); //(x,y) where the line graph begins
         content
                .height(tft.height() - header.height() * 1.5) //actual height of the line chart
                .width(tft.width() - content.x() * 2) //actual width of the line chart
                .based_on(300) //Starting point of y-axis, must be a float
                .show_circle(false) //drawing a cirle at each point, default is on
                .value(data) //passing through the data to line graph
                .color(TFT_RED) //setting line graph color
                .draw(); //draw line graph
 
    spr.pushSprite(0, 0); //push to LCD
    delay(50);
}
