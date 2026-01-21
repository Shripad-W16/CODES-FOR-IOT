//project by shripad ->>


#include <Arduino.h>

#define CRACK_SENSOR 2
#define BUZZER 8
#define RED_LED 9



#define GREEN_LED 10

void setup() {
    Serial.begin(9600);

    pinMode(CRACK_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

    Serial.println("Railway Track Monitoring System Started...");
}

void loop() {
    int crackStatus = digitalRead(CRACK_SENSOR);

    if (crackStatus == HIGH) {
        Serial.println("CRACK DETECTED ON TRACK!");
        digitalWrite(BUZZER, HIGH);
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
    } 
    else {
        Serial.println("Track Condition Normal");
        digitalWrite(BUZZER, LOW);
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
    }

    delay(2000);
}
