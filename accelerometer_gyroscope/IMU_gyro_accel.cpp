#include <Wire.h>

constexpr uint8_t MPU_ADDR = 0x68; // I2C address of the MPU-6050

//Variables for storing raw accel and gyro sensor data
float AccelX, AccelY, AccelZ;
float GyroX, GyroY, GyroZ;

float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
float roll, pitch, yaw;
float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
float elapsedTime, currentTime, previousTime;
int c = 0;

void setup() {
    Serial.begin(19200); // Twice normal buad rate

    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);

    Wire.write(0x6B);                  // Talk to the register 6B
    Wire.write(0x00);                  // Make reset - place a 0 into the 6B register

    Wire.endTransmission(true);

    calculate_IMU_error();
    delay(20);
}

void loop () {

}

void calculate_imu_error () {
    
}
