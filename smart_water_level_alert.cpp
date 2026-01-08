#include <Arduino.h>

#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 19

void setup() {
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.println("Smart Water Level Alert System Started");
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2;
    return distance;
}

void loop() {
    long waterLevel = getDistance();

    Serial.print("Water Distance from Sensor: ");
    Serial.print(waterLevel);
    Serial.println(" cm");

    if (waterLevel < 10) {
        Serial.println("⚠ Tank Full! Alert Activated");
        digitalWrite(BUZZER_PIN, HIGH);
    } else {
        digitalWrite(BUZZER_PIN, LOW);
    }

    delay(1000);
}
