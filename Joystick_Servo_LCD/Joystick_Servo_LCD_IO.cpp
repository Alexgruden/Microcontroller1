#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h> //Needed to communicate to I2C
// Found LCD address by using arduino i2c scanner from: File -> Examples -> Wire -> i2c_scanner

constexpr int JOYSTICK_X_PIN = A1; // Arduino pin connected to VRX pin
constexpr int JOYSTICK_Y_PIN = A0; // Arduino pin connected to VRY pin
constexpr int SERVO_PIN = 9;
constexpr uint8_t LCD_ADDRESS = 0x27; // uint8_t address being a byte sized protocol

Servo myservo;

//Joystick x and y
int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis

LiquidCrystal_I2C lcd(0x27,  16, 2);


void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
  while (!Serial); //wait for serial monitor to open

  //Lcd initializations
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  xValue = analogRead(JOYSTICK_X_PIN);
  yValue = analogRead(JOYSTICK_Y_PIN);
  int pos = (xValue * 180L) / 1023; //use long since int only goes up to 32k
  myservo.write(pos);

  Serial.print("X position = ");
  Serial.println(xValue);
  Serial.print("Y position = ");
  Serial.println(yValue);

  // Print Joystick Location on LCD 
  lcd.setCursor(0,0);
  char buffer[16]; //Buffer created to print to LCD
  snprintf(buffer, 16, "X: %04d Y: %04d", xValue, yValue);
  lcd.print(buffer);

  // Print  Servo Postition on LCD
  lcd.setCursor(0,1);
  char buffer1[16]; //Buffer created to print to LCD
  snprintf(buffer1, 16, "Servo pos: %03d", pos);
  lcd.print(buffer1);

  delay(200);
}
