#include "helpers/ultrasonic.h"

#define ECHO 13
#define TRIGGER 10
#define LED 8
#define RELAY 9

int minDistance = 5;  // In cm
int minLight = 300;

void setup() {
    Serial.begin(9600);

    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(RELAY, OUTPUT);
}

void loop() {
    turnLightsIfNeeded();

    int currentDistance = ping(TRIGGER, ECHO);
    int voltageToApply;

    if (currentDistance < minDistance) {
        voltageToApply = HIGH;
    } else {
        voltageToApply = LOW;
    }

    digitalWrite(LED, voltageToApply);
    Serial.print("Distance: ");
    Serial.println(currentDistance);
    Serial.flush();
}

void turnLightsIfNeeded() {
    int lightValue = analogRead(A0);
    int voltageToApply;

    if (lightValue <= minLight) {
        voltageToApply = HIGH;
    } else {
        voltageToApply = LOW;
    }

    digitalWrite(RELAY, voltageToApply);
}