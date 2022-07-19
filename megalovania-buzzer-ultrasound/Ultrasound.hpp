// Header Ultrasound Sensor file for Arduino
#ifndef Ultrasound_H
#define Ultrasound_H


using namespace std;

class Ultrasonic_Sensor {
    int trig_pin; // Pin for sound producer
    int echo_pin; // Pin for sound receiver

    int duration; // Amount of time that ultrasonic signal is detected
    double distanceCm; // Detected Distance in Cm
public:
    Ultrasonic_Sensor(int tpin, int epin);
    double getDistanceCm();
};

#endif
