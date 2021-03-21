int minDistance = 3;  // In cm

int ping(int TRIGGER, int ECHO) {
    long duration;

    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(4);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    duration = pulseIn(ECHO, HIGH);

    // Return distance in cm
    return ((duration * 10) / 292) / 2;
}

bool hasToTurnLed(int TRIGGER, int ECHO) {
    int currentDistance = ping(TRIGGER, ECHO);
    int voltageToApply;

    Serial.println(currentDistance);

    return currentDistance <= minDistance;
}

void turnLedOn(int LED, byte hasToTurnLedOn) {
    digitalWrite(LED, hasToTurnLedOn);
    if (hasToTurnLedOn) {
        // We wait only for turn on light
        Serial.println("LED-ON");
        Serial.flush();
        delay(5000);
    }
}
