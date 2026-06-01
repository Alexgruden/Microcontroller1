#include <Arduino.h>
#include <Key.h>
#include <Keypad.h>

const char num_rows = 4;
const char num_cols = 4;

char keypad_row_pins[num_rows] = {9, 8, 7, 6};
char keypad_col_pins[num_cols] = {5, 4, 3, 2};

char key_array[num_rows][num_cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Keypad keypadObj = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
Keypad k = Keypad(makeKeymap(key_array), keypad_row_pins, keypad_col_pins, num_rows, num_cols);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key_pressed = k.getKey();

  if (key_pressed) {
    Serial.println(key_pressed);
  }
}



