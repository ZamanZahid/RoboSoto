/*
  RoboSoto

  IMU Figure 8 Navigation

  Uses the BNO055 IMU to navigate a figure-8
  course using heading-based control.
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

#define M1_EN 12
#define M1_PH 13

#define M2_EN 14
#define M2_PH 21

#define M3_EN 9
#define M3_PH 10

#define M4_EN 47
#define M4_PH 11

#define DRIVE_SPEED 76
#define INNER_RATIO 0.55

Adafruit_BNO055 bno = Adafruit_BNO055(55);

float getHeading()
{
  sensors_event_t event;
  bno.getEvent(&event);
  return event.orientation.x;
}

void stopMotors()
{
  analogWrite(M1_EN, 0);
  analogWrite(M2_EN, 0);
  analogWrite(M3_EN, 0);
  analogWrite(M4_EN, 0);
}

void setMotor(int dirPin, int pwmPin, bool direction, int speed)
{
  digitalWrite(dirPin, direction);
  analogWrite(pwmPin, speed);
}

void driveLeftLoop()
{
  int outerSpeed = DRIVE_SPEED;
  int innerSpeed = DRIVE_SPEED * INNER_RATIO;

  float accumulatedTurn = 0;
  float previousHeading = getHeading();

  setMotor(M1_PH, M1_EN, HIGH, innerSpeed);
  setMotor(M2_PH, M2_EN, LOW, outerSpeed);

  setMotor(M3_PH, M3_EN, HIGH, innerSpeed);
  setMotor(M4_PH, M4_EN, LOW, outerSpeed);

  while (accumulatedTurn > -360.0)
  {
    float currentHeading = getHeading();

    float delta = currentHeading - previousHeading;

    if (delta > 180) delta -= 360;
    if (delta < -180) delta += 360;

    accumulatedTurn += delta;

    previousHeading = currentHeading;

    delay(10);
  }

  stopMotors();
}

void driveRightLoop()
{
  int outerSpeed = DRIVE_SPEED;
  int innerSpeed = DRIVE_SPEED * INNER_RATIO;

  float accumulatedTurn = 0;
  float previousHeading = getHeading();

  setMotor(M1_PH, M1_EN, HIGH, outerSpeed);
  setMotor(M2_PH, M2_EN, LOW, innerSpeed);

  setMotor(M3_PH, M3_EN, HIGH, outerSpeed);
  setMotor(M4_PH, M4_EN, LOW, innerSpeed);

  while (accumulatedTurn < 360.0)
  {
    float currentHeading = getHeading();

    float delta = currentHeading - previousHeading;

    if (delta > 180) delta -= 360;
    if (delta < -180) delta += 360;

    accumulatedTurn += delta;

    previousHeading = currentHeading;

    delay(10);
  }

  stopMotors();
}

void moveForward(int timeMS)
{
  setMotor(M1_PH, M1_EN, HIGH, DRIVE_SPEED);
  setMotor(M2_PH, M2_EN, LOW, DRIVE_SPEED);

  setMotor(M3_PH, M3_EN, HIGH, DRIVE_SPEED);
  setMotor(M4_PH, M4_EN, LOW, DRIVE_SPEED);

  delay(timeMS);

  stopMotors();
}

void setup()
{
  Serial.begin(115200);

  pinMode(M1_PH, OUTPUT);
  pinMode(M2_PH, OUTPUT);
  pinMode(M3_PH, OUTPUT);
  pinMode(M4_PH, OUTPUT);

  pinMode(M1_EN, OUTPUT);
  pinMode(M2_EN, OUTPUT);
  pinMode(M3_EN, OUTPUT);
  pinMode(M4_EN, OUTPUT);

  Wire.begin(7, 15);

  if (!bno.begin())
  {
    Serial.println("BNO055 NOT FOUND");

    while (1);
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  delay(3000);

  driveLeftLoop();

  delay(300);

  moveForward(1200);

  delay(300);

  driveRightLoop();

  stopMotors();

  Serial.println("FIGURE 8 COMPLETE");
}

void loop()
{
}