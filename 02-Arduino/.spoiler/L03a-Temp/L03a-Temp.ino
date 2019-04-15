
// https://github.com/adafruit/DHT-sensor-library
#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    return;
  }

	Serial.print("Teplota je:" + t + " stupňů Celsia");
	Serial.print(",");
	Serial.println("Vlhkost je" + h + " %");
}
