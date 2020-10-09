void setup() {
  pinMode(WIO_BUZZER, OUTPUT); //Setting buzzer pin as OUTPUT
}

void loop() {
  //beep the buzzer for 1 second 
  analogWrite(WIO_BUZZER, 150); 
  delay(1000); 
  //Silence the buzzer for 1 second 
  analogWrite(WIO_BUZZER, 0);
  delay(1000);
}
