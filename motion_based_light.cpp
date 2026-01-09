#include <Arduino.h>

// Pin definitions
const int PIR_SENSOR_PIN = 7;   // PIR motion sensor
const int LIGHT_PIN = 8;        // LED / relay module

void setup() {
    Serial.begin(9600);
    pinMode(PIR_SENSOR_PIN, INPUT);
    pinMode(LIGHT_PIN, OUTPUT);
    digitalWrite(LIGHT_PIN, LOW); // Light OFF initially
}

void loop() {
    int motionState = digitalRead(PIR_SENSOR_PIN);

    if (motionState == HIGH) {
        digitalWrite(LIGHT_PIN, HIGH);
        Serial.println("Motion detected: Light ON");
    } else {
        digitalWrite(LIGHT_PIN, LOW);
        Serial.println("No motion: Light OFF");
    }

    delay(1000); // Delay for stability
}

// Entry point
int main() {
    init();      // Arduino core initialization
    setup();

    while (true) {
        loop();
    }

    return 0;
}
