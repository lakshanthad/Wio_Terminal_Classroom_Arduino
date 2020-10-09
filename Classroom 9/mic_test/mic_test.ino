void setup() {
  pinMode(WIO_MIC, INPUT); //set mic pin as input 
  Serial.begin(115200); //start serial communication 
}
 
void loop() {
  int val = analogRead(WIO_MIC); //store analog readings from mic 
  Serial.println(val); //print mic readings 
  delay(200); //delay between readings 
}
