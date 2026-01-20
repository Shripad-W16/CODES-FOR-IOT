//project by Shripad -->
//language used --> C++
#include <Arduino.h>

#define SLOT1 2
#define SLOT2 3
#define SLOT3 4

#define LED_GREEN 10
#define LED_RED 11

int totalSlots = 3;
int occupied = 0;

bool isOccupied(int pin) {
    return digitalRead(pin) == LOW;
}

void setup() {
    Serial.begin(9600);

    pinMode(SLOT1, INPUT);
    pinMode(SLOT2, INPUT);
    pinMode(SLOT3, INPUT);

    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);
}

void loop() {
    occupied = 0;

    if (isOccupied(SLOT1)) occupied++;
    if (isOccupied(SLOT2)) occupied++;
    if (isOccupied(SLOT3)) occupied++;

    Serial.println("---- Parking Status ----");
    Serial.print("Total Slots: "); Serial.println(totalSlots);
    Serial.print("Occupied Slots: "); Serial.println(occupied);
    Serial.print("Available Slots: "); Serial.println(totalSlots - occupied);

    if (occupied == totalSlots) {
        digitalWrite(LED_RED, HIGH);
        digitalWrite(LED_GREEN, LOW);
        Serial.println("🚫 Parking Full");
    } else {
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_RED, LOW);
        Serial.println("✅ Parking Available");
    }

    delay(3000);
}
