//codes by shripad -->
#include <Arduino.h>

#define LDR_PIN A0
#define CURRENT_SENSOR_PIN A1
#define LIGHT_RELAY_PIN 7

const int LIGHT_THRESHOLD = 400;
const float MIN_WORKING_CURRENT = 0.2;

void setup() {
    Serial.begin(9600);
    pinMode(LIGHT_RELAY_PIN, OUTPUT);
    Serial.println("Smart Street Light System Initialized");
}

void loop() {
    int lightValue = analogRead(LDR_PIN);
    int currentSensor = analogRead(CURRENT_SENSOR_PIN);

    float voltage = (currentSensor * 5.0) / 1023.0;
    float current = (voltage - 2.5) / 0.066;

    Serial.print("Ambient Light: ");
    Serial.print(lightValue);
    Serial.print(" | Load Current: ");
    Serial.print(abs(current));
    Serial.println(" A");

    if (lightValue < LIGHT_THRESHOLD) {
        digitalWrite(LIGHT_RELAY_PIN, HIGH);

        if (abs(current) < MIN_WORKING_CURRENT) {
            Serial.println("❌ Fault Detected: Street Light Not Working");
        }
    } else {
        digitalWrite(LIGHT_RELAY_PIN, LOW);
    }

    delay(1500);
}
