// Zadanie 1Wire
// podłączamy 2 termometry i odczytujemy temperatury z terminala (ctrl+shift+M).
// potrzebne będą 2 dodatkowe biblioteki które będą tutaj: http://www.hobbytronics.co.uk/ds18b20-arduino

#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 2			// pin 2 na arduino

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  Serial.begin(9600);
  Serial.println("Install Gentoo");
  sensors.begin();
} 
void loop(void)
{
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); 
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");		
  Serial.print(sensors.getTempCByIndex(0)); 		// 1 termometr
  Serial.print(" Temperature for Device 2 is: ");
  Serial.print(sensors.getTempCByIndex(1)); 		// 2 termometr
}