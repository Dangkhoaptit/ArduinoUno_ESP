//COM5
#include <SoftwareSerial.h>
#include <DHT.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

const int DHTPIN = 4;
const int DHTTYPE = DHT11;
const int buttonPin = 2;

DHT dht(DHTPIN,DHTTYPE);

//SoftwareSerial unoSerial(11,12);  //11 rx; 12- tx
String DHT11_TEMP, DHT11_HUMI;
unsigned int threshold  = 20;

unsigned long times;

void incThreshold()
{
  while(!digitalRead(buttonPin))
  {
  }
  threshold += 1;
  Serial.println(threshold);
}

void setup() {
  dht.begin();
  
  Serial.begin(9600);
  delay(500);
  Serial.println("send from Uno");

  pinMode(buttonPin, INPUT_PULLUP);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,0);

  attachInterrupt(0, incThreshold, RISING);

  times = millis();
}

void loop() {
  if (((unsigned long) (millis() - times) >1000) && ((unsigned long) (millis() - times) < 2000)){
    float t = dht.readTemperature(); 
    DHT11_TEMP = "tem";
    DHT11_TEMP.concat(t);
    Serial.println(DHT11_TEMP);
   // times = millis();
  }
  else if ((unsigned long) (millis() - times) > 2000){
    float h = dht.readHumidity();
    DHT11_HUMI = "hum";
    DHT11_HUMI.concat(h);
    Serial.println(DHT11_HUMI); 
    times = millis();  
  }
//  if( t> threshold)
//  {
//    digitalWrite(13,1);
//    delay(100);
//  }
                 
 // delay(1000);

 
//  delay(1000);

  

}
