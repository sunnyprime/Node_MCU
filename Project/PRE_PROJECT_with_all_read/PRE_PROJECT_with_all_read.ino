#include <DHT.h>  
#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define DHTPIN 0  
#define DHTTYPE DHT11

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE);  
const char* ssid = "SUNNY PRIMEA";  
const char* password = "asdfghjkl";  
WiFiClient client;  

int t; 
uint8_t temperature, humidity,M;
int Moisture;  
int RED=5;
int GREEN=16;
int Soil_moisture= 17;
int A=0;

void setup()  
{  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(115200);  
  dht.begin();  
  delay(10);
//  sensors.begin();
    
  // Connect to WiFi network  
  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
  // Print the IP address  
  Serial.println(WiFi.localIP());
      
}

void loop() {


  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Moisture=analogRead(Soil_moisture);
  M=(1024-Moisture)/3;

  Serial.print("Present Temperature is: ");
  Serial.print(temperature);
  Serial.print("C \t Present Humidity is: ");
  Serial.print(humidity);
  Serial.print("% \t Soil Moisture is: ");
  Serial.println(M);
  Serial.println(Moisture);
  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0));

  if(M>55)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
  }
  else
  {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }
  

  delay(200);
  
}





