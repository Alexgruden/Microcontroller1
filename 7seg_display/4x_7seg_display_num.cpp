#include <Arduino.h>

// a, b, c, d, e, f, g
int segment_pin[7] = {13, 7, 9, 10, 11, 12, 8};
// d4, d3, d2, d1
int digit_pin[4] = {3, 4, 5, 6};
// Array for respective number from segments
int seg_to_num[10][7] = {
  //a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

int timer = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // buad rate

  //Loop to activate all pins at once instead of multiple small statements
  for (int i = 0; i < 7; i++) {
    pinMode(segment_pin[i], OUTPUT);
  }

  // i already used, use j
  for (int j = 0; j < 4; j++) {
    pinMode(digit_pin[j], OUTPUT);
  }
}

void loop() {
  Serial.print("Enter a number to be displayed: ");

  // with no input do nothing
  while(Serial.available() == 0) { }

  int num = (Serial.parseInt());
  Serial.println(num);

  int d3 = num / 1000; 
  int d2 = (num % 1000) / 100;
  int d1 = (num % 100) / 10;
  int d0 = num % 10;
  
  for (int k = 0; k < timer; k++) {
    //write to thousands digit
    digitalWrite(digit_pin[0], LOW);
    digitalWrite(digit_pin[1], HIGH);
    digitalWrite(digit_pin[2], HIGH);
    digitalWrite(digit_pin[3], HIGH);

    for (int i = 0; i < 7; i++) {
      // cycle through segment pins -> write high or low according to that digits required segments
      digitalWrite(segment_pin[i], seg_to_num[d3][i]);
    }
    delay(5);

    // write to hundreds digit
    digitalWrite(digit_pin[0], HIGH);
    digitalWrite(digit_pin[1], LOW);
    digitalWrite(digit_pin[2], HIGH);
    digitalWrite(digit_pin[3], HIGH);

    for (int i = 0; i < 7; i++) {
      // cycle through segment pins -> write high or low according to that digits required segments
      digitalWrite(segment_pin[i], seg_to_num[d2][i]);
    }
    delay(5);

    // tens digit 
    digitalWrite(digit_pin[0], HIGH);
    digitalWrite(digit_pin[1], HIGH);
    digitalWrite(digit_pin[2], LOW);
    digitalWrite(digit_pin[3], HIGH);

    for (int i = 0; i < 7; i++) {
      // cycle through segment pins -> write high or low according to that digits required segments
      digitalWrite(segment_pin[i], seg_to_num[d1][i]);
    }
    delay(5);

    // ones digit 
    digitalWrite(digit_pin[0], HIGH);
    digitalWrite(digit_pin[1], HIGH);
    digitalWrite(digit_pin[2], HIGH);
    digitalWrite(digit_pin[3], LOW);

    for (int i = 0; i < 7; i++) {
      // cycle through segment pins -> write high or low according to that digits required segments
      digitalWrite(segment_pin[i], seg_to_num[d0][i]);
    }
    delay(5);
  }

  // clear all digits
  for (int j = 0; j < 4; j++) {
    digitalWrite(digit_pin[j], HIGH);
  }

}