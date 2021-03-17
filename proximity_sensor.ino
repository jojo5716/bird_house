#include <LiquidCrystal.h>

#include "helpers/ultrasonic.h"

#define ECHO 13
#define TRIGGER 10
#define LED 8

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
int minDistance = 3;  // 7 cm

void setup() {
    Serial.begin(9600);

    lcd.begin(16, 2);

    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    int cm = ping(TRIGGER, ECHO);
    if (cm <= minDistance) {
        digitalWrite(LED, HIGH);
        Serial.println(cm);
    } else {
        digitalWrite(LED, LOW);
    }
}
