#include"LIS3DHTR.h" //include the accelerometer library
#include"seeed_line_chart.h" //include the line chart library

TFT_eSPI tft; //TFT LCD initialization
LIS3DHTR<TwoWire>  lis; //Accelerometer initialization
 
#define max_size 50 //maximum size of data
doubles accelerator_readings[3]; //array to store accelerometer values in x,y,z directions 
TFT_eSprite spr = TFT_eSprite(&tft); //create buffer 
 
void setup() {
    tft.begin(); //start TFT LCD
    tft.setRotation(3); //set screen rotation
    spr.createSprite(TFT_HEIGHT,TFT_WIDTH); //create buffer 
 
    lis.begin(Wire1); //start accelerometer 
    lis.setOutputDataRate(LIS3DHTR_DATARATE_25HZ); //Data output rate (5Hz up to 5kHz)
    lis.setFullScaleRange(LIS3DHTR_RANGE_2G); //Scale range (2g up to 16g)
 
    Serial.begin(115200); //Start serial communication
}
 
void loop() {
    spr.fillSprite(TFT_WHITE); //fill background 
    
    float x_raw = lis.getAccelerationX(); //create variable to store x-axis accelerometer values 
    float y_raw = lis.getAccelerationY(); //create variable to store y-axis accelerometer values 
    float z_raw = lis.getAccelerationZ(); //create variable to store z-axis accelerometer values 
 
    if (accelerator_readings[0].size() == max_size) {
      for (uint8_t i = 0; i<3; i++){
        accelerator_readings[i].pop(); //Used to remove the first read variable
      }
    }
    accelerator_readings[0].push(x_raw); //store x-axis accelerometer values in array
    accelerator_readings[1].push(y_raw); //store y-axis accelerometer values in array
    accelerator_readings[2].push(z_raw); //store z-axis accelerometer values in array
 
    //Settings for the line graph title
    auto header =  text(0, 0) //starting coordinates of text 
                .value("Acceleration Readings") //text string 
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
                .based_on(-2.0) //Starting point of y-axis, must be a float
                .show_circle(false) //drawing a cirle at each point, default is on
                .value({accelerator_readings[0],accelerator_readings[1], accelerator_readings[2]}) //passing through the readings to line graph
                .color(TFT_BLUE, TFT_RED, TFT_GREEN) //setting line graph colors 
                .draw(); //draw line graph 
 
    spr.pushSprite(0, 0); //push to LCD
    delay(50);
}
