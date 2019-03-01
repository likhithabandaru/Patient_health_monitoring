#include<SoftwareSerial.h>
#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>   
LiquidCrystal lcd(7,6,5,4,3,2); 
SoftwareSerial s(8,9);
int sensorValue = 0;        // value read from the pot
int outputValue = 0;   
const int PulseWire = 0; 
const int analogOutPin = A1;
const int LED13 = 13;     
int Threshold = 550;
PulseSensorPlayground pulseSensor;  
void setup() {   
Serial.begin(9600);
s.begin(9600);
lcd.begin(16,2); 
lcd.setCursor(0, 0);
lcd.println("Heart beat checker");
delay(2000);
pulseSensor.analogInput(PulseWire);   
pulseSensor.blinkOnPulse(LED13);    
pulseSensor.setThreshold(Threshold);    
if (pulseSensor.begin()) {
Serial.println("We created a pulseSensor Object !"); 
}
}
void loop() {
int myBPM = pulseSensor.getBeatsPerMinute();
if (pulseSensor.sawStartOfBeat()) {            
Serial.println("?  A HeartBeat Happened ! "); 
Serial.print("BPM: ");                        
Serial.println(myBPM);
lcd.clear();  
lcd.setCursor(0, 0);
lcd.println("   Pulse Rate   "); 
lcd.setCursor(0, 1);
lcd.print("Beat Per Min:");                       
lcd.print(myBPM);
 s.write(myBPM);
  delay(1000);
delay(100);
}
}
