//a project by shripad -->>

#include <Arduino.h>

#define CURRENT_SENSOR A0
#define RELAY 7
#define BUZZER 6

float currentValue = 0;
float power = 0;
float voltage = 230.0;   // Standard AC voltage
float overloadLimit = 1500.0; // Watts

void setup() {
    Serial.begin(9600);

    pinMode(RELAY, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    digitalWrite(RELAY, HIGH);  // Power ON

    Serial.println("Smart Energy Meter System Started...");
}

float readCurrent() {
    int val = analogRead(CURRENT_SENSOR);
    return (val * 10.0) / 1023.0;   // Simulated current calculation
}

void loop() {
    currentValue = readCurrent();
    power = voltage * currentValue;

    Serial.println("---- Energy Monitoring Report ----");
    Serial.print("Current (A): "); Serial.println(currentValue);
    Serial.print("Power (W): "); Serial.println(power);

    if (power > overloadLimit) {
        Serial.println("⚠️ OVERLOAD DETECTED! Power Cut Off.");
        digitalWrite(RELAY, LOW);   // Cut supply
        digitalWrite(BUZZER, HIGH);
    } 
    else {
        Serial.println("✅ Power Usage Normal");
        digitalWrite(RELAY, HIGH);
        digitalWrite(BUZZER, LOW);
    }

    delay(3000);
}
