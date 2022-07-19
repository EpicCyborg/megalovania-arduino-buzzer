// Entire Megalovania song on Arduino Buzzer -- altered pitch and tempo from the arduino ultrasonic sensor
// Prints distance in cm detected 
#include "Ultrasound.hpp"

int part_a_duration[] = { 2, 2, 2, 2, 4, 4,
6, 6, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2 };

int part_a_notes[] = { 62, 0, 62, 0, 74, 0,
69, 0, 68, 0, 67, 0, 65, 0, 62, 0, 65, 0, 67, 0 };
int size_a = sizeof(part_a_duration) / sizeof(part_a_duration[0]);

int part_b_duration[] = { 4, 4, 2, 2, 4, 4,
4, 4, 4, 4, 4, 4, 10, 10, 4, 4, 2, 2, 4, 4, 4, 4,
4, 4, 2, 2, 2, 2, 2, 2, 2, 2 , 6, 6, 4, 4, 2, 2,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 6, 6, 4, 4, 4, 4,
2, 2, 2, 2, 2, 2, 18, 18, 4, 4, 2, 2, 4, 4, 4, 4,
4, 4, 4, 4, 10, 10, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4,
18, 18 };

int part_b_notes[] = { 77, 0, 77, 0, 77, 0,
77, 0, 77, 0, 74, 0, 74, 0, 77, 0, 77, 0, 77, 0, 79, 0,
80, 0, 79, 0, 77, 0, 74, 0, 77, 0, 79, 0, 77, 0, 77, 0,
77, 0, 79, 0, 80, 0, 81, 0, 84, 0, 81, 0, 86, 0, 86, 0,
86, 0, 81, 0, 86, 0, 84, 0, 81, 0, 81, 0, 81, 0, 81, 0,
81, 0, 79, 0, 79, 0, 81, 0, 81, 0, 81, 0, 81, 0, 79, 0,
81, 0, 86, 0, 81, 0, 79, 0, 86, 0, 81, 0, 79, 0, 77, 0,
84, 0, 79, 0, 77, 0, 76, 0, 70, 0, 72, 0, 74, 0, 77, 0,
84, 0 };
int size_b = sizeof(part_b_duration) / sizeof(part_b_duration[0]);

int part_c_duration[] = { 32, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1,
1, 1, 4, 4, 18, 18, 4, 4, 2, 2, 4, 4, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 18, 18, 4, 4, 4, 4,
4, 4, 4, 4, 14, 2, 14, 2, 14,2, 14, 2, 14, 2, 14, 2,
30, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 26, 2, 32, 4 };

int part_c_notes[] = { 0, 77, 0, 74, 0, 77, 0,
79, 0, 80, 0, 79, 0, 77, 0, 74, 0, 80, 0, 79, 0, 77, 0,
74, 0, 77, 0, 79, 0, 80, 0, 81, 0, 84, 0, 81, 0, 80, 0,
79, 0, 77, 0, 74, 0, 76, 0, 77, 0, 79, 0, 81, 0, 84, 0,
85, 0, 80, 0, 80, 0, 79, 0, 77, 0, 79, 0, 65, 0, 67, 0,
69, 0, 77, 0, 76, 0, 74, 0, 76, 0, 77, 0, 79, 0, 76, 0,
81, 0, 81, 0, 80, 0, 79, 0, 78, 0, 77, 0, 76, 0, 75, 0,
74, 0, 73, 0, 75, 0 };
int size_c = sizeof(part_c_duration) / sizeof(part_c_duration[0]);

int part_d_duration[] = { 48, 16, 32,
30 , 2 , 64, 64 };

int part_d_notes[] = { 58, 65, 64,
62,0, 65, 0 };
int size_d = sizeof(part_d_duration) / sizeof(part_d_duration[0]);

int part_e_duration[] = { 8, 4, 4, 6, 6, 4, 4,
4, 4, 4, 4, 2, 2, 2, 2, 2, 2 };

int part_e_notes[] = { 0, 77, 0, 76, 0, 72, 0,
76, 0, 74, 0, 69, 0, 72, 0, 74, 0 };
int size_e = sizeof(part_e_duration) / sizeof(part_e_duration[0]);

int part_f_duration[] = { 4, 4, 4, 4, 2, 2,
4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 4, 4, };

int part_f_notes[] = { 70, 0, 70, 0, 70, 0,
70, 0, 70, 0, 70, 0, 70, 0, 70, 0, 70, 0 };
int size_f = sizeof(part_f_duration) / sizeof(part_f_duration[0]);

// Variables
const int buzzer_pin = 2;
double power; // Part of the MIDI to frequency conversion equation
float frequency; // Frequency that the buzzer plays
float duration; // duration of note in milliseconds
float BPM = 230; // Quarter notes per minute
float TPQ = 8; // Ticks per quarter note
float pitch = 1; // Multiplier for frequency

const float distance_range[2] = { 58,170 }; // Distance range for the ultrasonic sensor to detect

// Ultrasonic Sensor Variables
double distanceCm;
Ultrasonic_Sensor ultrasonic(11, 12); // Set up Ultrasonic ultrasonic object with pins (trig, echo)

void setup() {
  //Serial Port begin
  Serial.begin(9600);
}


void loop() {
  // Entire Megalovania loop
  int offsets[] = { 0,0,12,12 };
  int first_notes[4] = { 0,-2,-3,-4 };

  for (const int k : offsets) {
    for (const int j : first_notes) {
      PartA(j, k);
    }
  }
  PartB();
  PartC();
  PartC();
  PartD();
  int first_notes2[6] = { 0,-2,-3,-3,0,-2 };
  for (const int j : first_notes2) {
    PartA(j, 0);
  }
  PartE();
  PartE();
  PartF(0, 0);
  PartF(2, 2);
  PartF(4, 3);
  PartF(2, 1);
  PartF(0, 0);
  PartF(2, 2);
  int first_notes3[8] = { 0, 0,-4,-2, 0, 0, -4, -2 };
  for (const int j : first_notes3) {
    PartA(j, 0);
  }
}

// The main melody of the song -- The first two notes can be manipulated:
void PartA(int first_note, int offset) { // First variable changes the first 2 notes, second allows for shifting the key of the whole part
  for (int i = 0;i < size_a;i++) {
    duration = part_a_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
    if (part_a_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
      noTone(buzzer_pin);
      delay(duration);
    }
    else {
      if (i == 0 || i == 2) {
        power = (part_a_notes[i] - 69 + first_note + offset) / (double)12; // Part of the MIDI to frequency conversion equation
      }
      else {
        power = (part_a_notes[i] - 69 + offset) / (double)12; // Part of the MIDI to frequency conversion equation
      }
      distanceCm = ultrasonic.getDistanceCm();
      if (distanceCm > 0) {
        BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
        pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
        Serial.println(distanceCm);
      }
      frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
      tone(buzzer_pin, frequency); // Play the frequency on the buzzer
      delay(duration); // Duration of note in milliseconds 
    }
  }
}

void PartB() {
  for (int i = 0;i < size_b;i++) {
    duration = part_b_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
    if (part_b_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
      noTone(buzzer_pin);
      delay(duration);
    }
    else {
      power = (part_b_notes[i] - 69) / (double)12; // Part of the MIDI to frequency conversion equation

      distanceCm = ultrasonic.getDistanceCm();
      if (distanceCm > 0) {
        BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
        pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
        Serial.println(distanceCm);
      }
      frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
      tone(buzzer_pin, frequency); // Play the frequency on the buzzer
      delay(duration); // Duration of note in milliseconds 
    }
  }
}

void PartC() {
  for (int i = 0;i < size_c;i++) {
    duration = part_c_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
    if (part_c_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
      noTone(buzzer_pin);
      delay(duration);
    }
    else {
      power = (part_c_notes[i] - 69) / (double)12; // Part of the MIDI to frequency conversion equation

      distanceCm = ultrasonic.getDistanceCm();
      if (distanceCm > 0) {
        BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
        pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
        Serial.println(distanceCm);
      }
      frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
      tone(buzzer_pin, frequency); // Play the frequency on the buzzer
      delay(duration); // Duration of note in milliseconds 
    }
  }
}

void PartD() {
  int last_note[] = { 0,-3 };
  for (const int j : last_note) {
    for (int i = 0;i < size_d;i++) {
      duration = part_d_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
      if (part_d_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
        noTone(buzzer_pin);
        delay(duration);
      }
      else {
        if (i == 5) {
          power = (part_d_notes[i] - 69 + j) / (double)12; // Part of the MIDI to frequency conversion equation
        }
        else {
          power = (part_d_notes[i] - 69) / (double)12; // Part of the MIDI to frequency conversion equation
        }
        distanceCm = ultrasonic.getDistanceCm();
        if (distanceCm > 0) {
          BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
          pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
          Serial.println(distanceCm);
        }
        frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
        tone(buzzer_pin, frequency); // Play the frequency on the buzzer
        delay(duration); // Duration of note in milliseconds 
      }
    }
  }
}

void PartE() {
  for (int i = 0;i < size_e;i++) {
    duration = part_e_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
    if (part_e_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
      noTone(buzzer_pin);
      delay(duration);
    }
    else {
      power = (part_e_notes[i] - 69) / (double)12; // Part of the MIDI to frequency conversion equation

      distanceCm = ultrasonic.getDistanceCm();
      if (distanceCm > 0) {
        BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
        pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
        Serial.println(distanceCm);
      }
      frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
      tone(buzzer_pin, frequency); // Play the frequency on the buzzer
      delay(duration); // Duration of note in milliseconds 
    }
  }
}

void PartF(int offset1, int offset2) {
  for (int i = 0;i < size_f;i++) {
    duration = part_f_duration[i] / TPQ / BPM * 60 * 1000; // Calculate duration in milliseconds from ticks
    if (part_f_notes[i] == 0) { // Check if volume value is 0, then silence the note for set duration
      noTone(buzzer_pin);
      delay(duration);
    }
    else {
      if (i < 8) {
        power = (part_f_notes[i] - 69 + offset1) / (double)12; // Part of the MIDI to frequency conversion equation 
      }
      else {
        power = (part_f_notes[i] - 69 + offset2) / (double)12; // Part of the MIDI to frequency conversion equation 
      }
      distanceCm = ultrasonic.getDistanceCm();
      if (distanceCm > 0) {
        BPM = map(distanceCm, distance_range[0], distance_range[1], 115, 345);
        pitch = map(distanceCm, distance_range[0], distance_range[1], 500, 1500) / 1000.0;
        Serial.println(distanceCm);
      }
      frequency = pitch * pow(2, power) * 440; // Frequency converted from MIDI note value
      tone(buzzer_pin, frequency); // Play the frequency on the buzzer
      delay(duration); // Duration of note in milliseconds 
    }
  }
}
