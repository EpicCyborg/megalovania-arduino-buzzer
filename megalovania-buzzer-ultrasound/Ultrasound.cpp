#include "Ultrasound.hpp"
#include <Arduino_AVRSTL.h>

// Ultrasonic_Sensor Class functions
Ultrasonic_Sensor::Ultrasonic_Sensor(int tpin, int epin) // Set up the pins for new Ultrasonic_Sensor object
    : trig_pin(tpin), echo_pin(epin) {
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
}
double Ultrasonic_Sensor::getDistanceCm() {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    duration = pulseIn(echo_pin, HIGH);
    distanceCm = duration * 0.034L / 2L;
    return distanceCm;
}
