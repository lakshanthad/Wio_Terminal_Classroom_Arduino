#include "DHT.h" //DHT library

#define DHTPIN 0 //Define Signal Pin of DHT

#define DHTTYPE DHT11 //Define DHT Sensor Type

DHT dht(DHTPIN, DHTTYPE); //Initializing DHT sensor


void setup() {
  Serial.begin(9600); //Start serial communication
  dht.begin(); //Start DHT sensor

}

void loop() {
  int t = dht.readTemperature(); //Assign variable to store temperature
  int h = dht.readHumidity(); //Assign variable to store humidity

  Serial.print("Temperature: ");
  Serial.println(t);  //print temperature values
  Serial.print("Humidity: ");
  Serial.println(h); //print humidity values

}
