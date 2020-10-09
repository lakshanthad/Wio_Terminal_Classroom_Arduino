int frequency = 4000; //Buzzer frequency
int cycle = 1000000/frequency; //one time period in microseconds (1s=1000000us)

void setup(){
  Serial.begin(9600); //start serial communication
  pinMode(WIO_BUZZER,OUTPUT); //set buzzer pin as OUTPUT
}
 
void loop() 
{
  digitalWrite(WIO_BUZZER,HIGH); //set buzzer pin to HIGH
  delayMicroseconds(cycle/2); //first half of the time period
  digitalWrite(WIO_BUZZER,LOW); //set buzzer pin to LOW
  delayMicroseconds(cycle/2); //second half of the time period
}
