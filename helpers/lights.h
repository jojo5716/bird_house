int minLight = 300;


byte hasToTurnLights() {
    int lightValue = analogRead(A0);
    int voltageToApply;

    if (lightValue <= minLight) {
        voltageToApply = HIGH;
    } else {
        voltageToApply = LOW;
    }

    return voltageToApply;
}