#include <Arduino.h>
#include <Stepper.h>

constexpr uint8_t encoderPinA = 2;
constexpr uint8_t encoderPinB = 3;
constexpr uint16_t stepsPerRevolution = 2048;
constexpr uint8_t encoderSteps = 20;

int8_t lastEncoderCount = 0;
volatile int8_t encoderPosCount = 0;
volatile bool bClockWise;


// Pins entered in sequence IN1-IN3-IN2-IN4
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderPinA), readMove, CHANGE); // Interupt on pin A to allow for a large rotation of encoder

  Serial.begin(9600);
}

void loop() {
  if (encoderPosCount != lastEncoderCount) {
    Serial.print ("Rotated: ");
    if (bClockWise){
      Serial.println ("clockwise");
    } else {
      Serial.println("counterclockwise");
    }
    Serial.print("Encoder Position: ");
    Serial.println(encoderPosCount);
  }
  lastEncoderCount = encoderPosCount; //update with most recent aVal
}

void readMove() { //Interrupt Service Routine (ISR)
  if (digitalRead(encoderPinB) != digitalRead(encoderPinA)) { // A change first = clockwise
    encoderPosCount ++;
    bClockWise = true;
  } else { // B changed first = counter clockwise
    encoderPosCount --;
    bClockWise = false;
  }
}
