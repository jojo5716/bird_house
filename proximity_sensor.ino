#include "helpers/lights.h"
#include "helpers/ultrasonic.h"

#define ECHO 13
#define TRIGGER 10
#define LED 8
#define RELAY 9

void setup() {
    Serial.begin(9600);

    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(RELAY, OUTPUT);
}

void loop() {
    // Turning relay when it is getting dark.
    byte isTurningLight = hasToTurnLights();
    digitalWrite(RELAY, isTurningLight);

    byte hasToTurnLedOn = hasToTurnLed(TRIGGER, ECHO) ? HIGH : LOW;
    turnLedOn(LED, hasToTurnLedOn);
}
