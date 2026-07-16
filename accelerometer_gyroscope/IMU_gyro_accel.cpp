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
