//smart_temperature_fan
// an idea of mine

#include <Arduino.h>

// Pin definitions
const int TEMP_SENSOR_PIN = A0;   // LM35 sensor
const int FAN_PIN = 9;            // Relay / transistor

void setup() {
    Serial.begin(9600);
    pinMode(FAN_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW);   // Fan OFF initially
}

void loop() {
    int sensorValue = analogRead(TEMP_SENSOR_PIN);
    float voltage = sensorValue * (5.0 / 1023.0);
    float temperature = voltage * 100.0; // LM35: 10mV per °C

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    if (temperature > 30.0) {
        digitalWrite(FAN_PIN, HIGH);
        Serial.println("Fan Status: ON");
    } else {
        digitalWrite(FAN_PIN, LOW);
        Serial.println("Fan Status: OFF");
    }

    delay(2000);
}

// Entry point
int main() {
    init();        // Arduino core initialization
    setup();

    while (true) {
        loop();
    }

    return 0;
}
