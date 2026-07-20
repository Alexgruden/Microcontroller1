#include "DHT.h"

constexpr uint8_t DHTPIN = 7;
constexpr uint8_t DHTTYPE = DHT22;
constexpr uint8_t FAN_PIN = 9;
constexpr uint8_t RELAY_PIN = 8;
constexpr float FAN_THRESHOLD = 60.0;    // Humidity % to activate fan
constexpr float RELAY_THRESHOLD = 80.0;  // Humidity % to activate relay

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    delay(2000);

    float humidity = dht.readHumidity();
    float tempCelsius = dht.readTemperature();
    float tempFahrenheit = dht.readTemperature(true);

    if (isnan(humidity) || isnan(tempCelsius) || isnan(tempFahrenheit)) {
        Serial.println(F("Failed to read from DHT22 sensor!"));
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("% | Temp: ");
    Serial.print(tempCelsius);
    Serial.print("C / ");
    Serial.print(tempFahrenheit);
    Serial.println("F");

    // Fan control
    if (humidity > FAN_THRESHOLD) {
        digitalWrite(FAN_PIN, HIGH);
        Serial.println("Fan: ON");
    } else {
        digitalWrite(FAN_PIN, LOW);
        Serial.println("Fan: OFF");
    }

    // Relay control
    if (humidity > RELAY_THRESHOLD) {
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Relay: ON");
    } else {
        digitalWrite(RELAY_PIN, LOW);
        Serial.println("Relay: OFF");
    }
}