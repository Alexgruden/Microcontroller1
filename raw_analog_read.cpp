#include <Arduino.h>

int waitTime = 500;
int thermistorReadPin = 0;
int V0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Start of Data");
}

void loop() {
  // put your main code here, to run repeatedly:
  V0 = analogRead(thermistorReadPin);
  Serial.println(V0);
  delay(waitTime);
}
