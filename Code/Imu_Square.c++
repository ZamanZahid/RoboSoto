/*
  RoboSoto

  IMU Square Navigation

  Uses the BNO055 IMU to perform precise
  90-degree turns and drive in a square.
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

Adafruit_BNO055 bno = Adafruit_BNO055(55);

int driveSpeed = 120;

float getHeading() {
  sensors_event_t event;
  bno.getEvent(&event);
  return event.orientation.x;
}

void stopMotors() {

  analogWrite(M1_EN, 0);
  analogWrite(M2_EN, 0);
  analogWrite(M3_EN, 0);
  analogWrite(M4_EN, 0);
}

void forward() {

  digitalWrite(M1_PH, HIGH);
  analogWrite(M1_EN, driveSpeed);

  digitalWrite(M2_PH, LOW);
  analogWrite(M2_EN, driveSpeed);

  digitalWrite(M3_PH, HIGH);
  analogWrite(M3_EN, driveSpeed);

  digitalWrite(M4_PH, LOW);
  analogWrite(M4_EN, driveSpeed);
}

void turnRight() {

  digitalWrite(M1_PH, HIGH);
  analogWrite(M1_EN, driveSpeed);

  digitalWrite(M2_PH, HIGH);
  analogWrite(M2_EN, driveSpeed);

  digitalWrite(M3_PH, HIGH);
  analogWrite(M3_EN, driveSpeed);

  digitalWrite(M4_PH, HIGH);
  analogWrite(M4_EN, driveSpeed);
}

void turn90Degrees() {

  float startHeading = getHeading();

  turnRight();

  while (true) {

    float currentHeading = getHeading();

    float difference = currentHeading - startHeading;

    if (difference < 0)
      difference += 360;

    if (difference >= 90)
      break;

    delay(5);
  }

  stopMotors();
}

void driveSide() {

  forward();
  delay(1500);

  stopMotors();
  delay(300);
}

void setup() {

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

  if (!bno.begin()) {

    Serial.println("BNO055 NOT FOUND");

    while (1);
  }

  delay(1000);

  bno.setExtCrystalUse(true);

  delay(3000);

  for (int i = 0; i < 4; i++) {

    driveSide();

    turn90Degrees();

    delay(300);
  }

  stopMotors();

  Serial.println("SQUARE COMPLETE");
}

void loop() {
}