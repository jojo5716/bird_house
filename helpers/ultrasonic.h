int ping(int TriggerPin, int EchoPin) {
    long duration;

    digitalWrite(TriggerPin, LOW);
    delayMicroseconds(4);
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    duration = pulseIn(EchoPin, HIGH);

    // Return distance in cm
    return ((duration * 10) / 292) / 2;
}
