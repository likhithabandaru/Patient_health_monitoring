#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SPI.h>
#include <Wire.h>
const char* ssid = "****";
const char* password = "*****";
#define FIREBASE_HOST "*******"
#define FIREBASE_AUTH "*********"
float outputValue = 0;  
WiFiServer server(80);
int data;
void setup(){
  Serial.begin(9600); 
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
server.begin();
Serial.println("WiFi connected");
Serial.println("Server started");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop(){
 data = Serial.read();
 Serial.println(data);
 if(data>0){
Firebase.setFloat("Heartbeat", data);  
 }

delay(100);
}
