void setup() {
  pinMode(WIO_LIGHT, INPUT); //Setting light sensor pin as INPUT
  Serial.begin(9600); //Start Serial Communication

}

void loop() {
  int light = analogRead(WIO_LIGHT); //Store light sensor values in "light" variable
  Serial.print("Light Value: ");
  Serial.println(light);
  delay(200);

}
