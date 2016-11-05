#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

DHT dht(13, DHT11);

void setup()
{
  Serial.begin(115200);

  dht.begin();
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.println(t);

  delay(2000);
}
