void setup() {
    pinMode(WIO_BUZZER, OUTPUT); //set buzzer pin as OUTPUT
}
 
void loop() {
    analogWrite(WIO_BUZZER, 150); //write DAC value to buzzer (beep buzzer)
    delay(1000); //keep the buzzer beeping  
    analogWrite(WIO_BUZZER, 0); //turn off buzzer beep 
    delay(1000); //keep the buzzer beep turned off
}
