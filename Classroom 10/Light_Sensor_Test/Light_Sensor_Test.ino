void setup() {
  pinMode(WIO_LIGHT, INPUT); //set light sensor pin as INPUT 
  Serial.begin(115200); //start serial communication 

}

void loop() {
  int light = analogRead(WIO_LIGHT); //variable to store analog readings from light sensor 
  Serial.print("Light value: "); //print text 
  Serial.print(light); //print analog readings from light sensor 
  delay(200);
}
