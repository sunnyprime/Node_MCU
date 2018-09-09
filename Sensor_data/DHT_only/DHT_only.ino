// Libraries
#include "DHT.h"
#include "ESP8266WiFi.h"
#include <aREST.h>
// Pin
#define DHTPIN 5
// Use DHT11 sensor
#define DHTTYPE DHT11
// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE, 15);


const char* ssid = "SUNNY AIRTEL";
const char* password = "asdfghjkl";

aREST rest = aREST();

int soil= 17;
int temperature;
int humidity;

WiFiServer server(80);

void setup() {

// Start Serial
Serial.begin(115200);
WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

// Init DHT
dht.begin();
}

void loop() {

read();

}





void read()
{
  // Reading soil moisture
float M=analogRead(soil);
  // Reading temperature and humidity
float h = dht.readHumidity();
// Read temperature as Celsius
float t = dht.readTemperature();

// Display data
Serial.print("Humidity: ");
Serial.print(h);
Serial.print(" %\t");
Serial.print("Temperature: ");
Serial.print(t);
Serial.print(" *C ");
Serial.print("\t Soil Moisture:");
Serial.print(M);
Serial.println(" %MC");

// Wait a few seconds between measurements.
delay(2000);
}


