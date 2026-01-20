#include <Arduino.h>

#define PH_PIN A0
#define TURBIDITY_PIN A1
#define TDS_PIN A2
#define BUZZER 9

float readPH() {
    int val = analogRead(PH_PIN);
    return (val * 14.0) / 1023.0;
}

float readTurbidity() {
    int val = analogRead(TURBIDITY_PIN);
    return (val * 100.0) / 1023.0;
}

float readTDS() {
    int val = analogRead(TDS_PIN);
    return (val * 500.0) / 1023.0;
}

void setup() {
    Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    float ph = readPH();
    float turbidity = readTurbidity();
    float tds = readTDS();

    Serial.println("---- Water Quality Report ----");
    Serial.print("pH: "); Serial.println(ph);
    Serial.print("Turbidity: "); Serial.println(turbidity);
    Serial.print("TDS: "); Serial.println(tds);

    if (ph < 6.5 || ph > 8.5 || turbidity > 50 || tds > 300) {
        Serial.println("⚠️ Water is UNSAFE!");
        digitalWrite(BUZZER, HIGH);
    } else {
        Serial.println("✅ Water is SAFE");
        digitalWrite(BUZZER, LOW);
    }

    delay(5000);
}
