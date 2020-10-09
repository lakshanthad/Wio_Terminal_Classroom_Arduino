int sensorPin = A0; //Define variable to store sensor pin
int sensorValue = 0; //Define variable to store sensor value

void setup() {
  Serial.begin(9600); //start serial communication

}

void loop() {
  sensorValue = analogRead(sensorPin); //Store sensor values into "sensorValue" variable
  Serial.print("Soil Moisture: ");
  Serial.println(sensorValue); //Print sensor values 
  delay(1000);

}
