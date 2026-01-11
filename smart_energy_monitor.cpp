//codes by shripad -->
#include <Arduino.h>

#define CURRENT_SENSOR_PIN A0
#define RELAY_PIN 8

const float CURRENT_THRESHOLD = 2.5;   // Amps (safe limit)
const float SENSOR_SENSITIVITY = 0.066; // ACS712 30A module

void setup() {
    Serial.begin(9600);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH); // Load ON
    Serial.println("Smart Energy Monitor Started");
}

float readCurrent() {
    int sensorValue = analogRead(CURRENT_SENSOR_PIN);
    float voltage = (sensorValue * 5.0) / 1023.0;
    float current = (voltage - 2.5) / SENSOR_SENSITIVITY;
    return abs(current);
}

void loop() {
    float current = readCurrent();

    Serial.print("Current Consumption: ");
    Serial.print(current);
    Serial.println(" A");

    if (current > CURRENT_THRESHOLD) {
        Serial.println("⚠ Overload Detected! Power Cut Off");
        digitalWrite(RELAY_PIN, LOW);
    } else {
        digitalWrite(RELAY_PIN, HIGH);
    }

    delay(1000);
}
