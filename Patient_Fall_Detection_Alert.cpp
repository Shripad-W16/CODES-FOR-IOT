#include <Arduino.h>

#define FALL_SENSOR A0   // Accelerometer simulated
#define BUZZER 6
#define ALERT_LED 7

float threshold = 2.5;   // Sudden acceleration threshold

void setup() {
    Serial.begin(9600);

    pinMode(BUZZER, OUTPUT);
    pinMode(ALERT_LED, OUTPUT);

    Serial.println("Patient Fall Detection System Started...");
}

float readAcceleration() {
    int val = analogRead(FALL_SENSOR);
    return (val * 5.0) / 1023.0;   // Simulated acceleration in g
}

void loop() {
    float accel = readAcceleration();

    Serial.print("Acceleration Level: ");
    Serial.println(accel);

    if (accel > threshold) {
        Serial.println("⚠️ FALL DETECTED! Emergency Alert Triggered.");
        digitalWrite(BUZZER, HIGH);
        digitalWrite(ALERT_LED, HIGH);
    } 
    else {
        Serial.println("✅ Patient Movement Normal");
        digitalWrite(BUZZER, LOW);
        digitalWrite(ALERT_LED, LOW);
    }

    delay(2000);
}
