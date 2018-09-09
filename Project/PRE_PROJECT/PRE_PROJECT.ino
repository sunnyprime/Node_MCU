#include <DHT.h>  
#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ThingSpeak.h> 
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define DHTPIN 0  
#define DHTTYPE DHT11

//DallasTemperature sensors(&oneWire);
DHT dht(DHTPIN, DHTTYPE);  
const char* ssid = "SUNNY PRIMEA";  
const char* password = "asdfghjkl";  
WiFiClient client;  
unsigned long myChannelNumber = 412690;  
const char * myWriteAPIKey = "07NKWPUWS8KXLIA3"; 
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
    
  ThingSpeak.begin(client);
    
}

void loop() {

static boolean data_state = false;  
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

//  if( data_state )  
//  {  
//   ThingSpeak.writeField(myChannelNumber, 1, temperature, myWriteAPIKey);
//   ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);
//   ThingSpeak.writeField(myChannelNumber, 3, M, myWriteAPIKey);  
//   data_state = false;  
//  }  
//  else  
//  {  
//   ThingSpeak.writeField(myChannelNumber, 2, humidity, myWriteAPIKey);  
//   data_state = true;  
//  }  

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





