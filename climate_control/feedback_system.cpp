#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    // Wait 2 seconds between measurements (DHT22 sampling rate is 0.5Hz)
    delay(2000);

// Read humidity (%)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float tempCelsius = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float tempFahrenheit = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(tempCelsius) || isnan(tempFahrenheit)) {
    Serial.println(F("Failed to read from DHT22 sensor!"));
    return;
  }
}