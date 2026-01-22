//project by shripad ->>

#include <Arduino.h>

#define COLOR_SENSOR A1
#define BUZZER 8
#define ALERT_LED 9

int healthyThreshold = 500;

void setup() {
    Serial.begin(9600);

    pinMode(BUZZER, OUTPUT);
    pinMode(ALERT_LED, OUTPUT);

    Serial.println("Smart Crop Disease Monitoring System Started...");
}

int readColorValue() {
    return analogRead(COLOR_SENSOR);
}

void loop() {
    int colorValue = readColorValue();

    Serial.print("Leaf Color Sensor Value: ");
    Serial.println(colorValue);

    if (colorValue < healthyThreshold) {
        Serial.println("⚠️ Possible Crop Disease Detected!");
        digitalWrite(BUZZER, HIGH);
        digitalWrite(ALERT_LED, HIGH);
    } 
    else {
        Serial.println("✅ Crop Condition Healthy");
        digitalWrite(BUZZER, LOW);
        digitalWrite(ALERT_LED, LOW);
    }

    delay(3000);
}
