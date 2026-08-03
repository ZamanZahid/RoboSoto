/*
  RoboSoto

  Wireless Joystick Control - Receiver

  Receives joystick commands through ESP-NOW
  and drives the robot.
*/

#include <esp_now.h>
#include <WiFi.h>

#define M1_DIR 13
#define M1_PWM 12

#define M2_DIR 21
#define M2_PWM 14

#define M3_DIR 10
#define M3_PWM 9

#define M4_DIR 11
#define M4_PWM 47

int speedValue = 120;

typedef struct {
  int x;
  int y;
  bool btn;
} JoystickData;

JoystickData incomingData;

void stopMotors() {

  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}

void moveForward() {

  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, speedValue);

  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, speedValue);

  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, speedValue);

  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, speedValue);
}

void moveBackward() {

  digitalWrite(M1_DIR, LOW);
  analogWrite(M1_PWM, speedValue);

  digitalWrite(M2_DIR, HIGH);
  analogWrite(M2_PWM, speedValue);

  digitalWrite(M3_DIR, LOW);
  analogWrite(M3_PWM, speedValue);

  digitalWrite(M4_DIR, HIGH);
  analogWrite(M4_PWM, speedValue);
}

void turnLeft() {

  digitalWrite(M1_DIR, LOW);
  analogWrite(M1_PWM, speedValue);

  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, speedValue);

  digitalWrite(M3_DIR, LOW);
  analogWrite(M3_PWM, speedValue);

  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, speedValue);
}

void turnRight() {

  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, speedValue);

  digitalWrite(M2_DIR, HIGH);
  analogWrite(M2_PWM, speedValue);

  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, speedValue);

  digitalWrite(M4_DIR, HIGH);
  analogWrite(M4_PWM, speedValue);
}

void OnDataRecv(const esp_now_recv_info_t *info,
                const uint8_t *data,
                int len) {

  memcpy(&incomingData, data, sizeof(incomingData));

  int x = incomingData.x;
  int y = incomingData.y;

  if (y > 3000) {
    moveForward();
  }
  else if (y < 1000) {
    moveBackward();
  }
  else if (x > 3000) {
    turnRight();
  }
  else if (x < 1000) {
    turnLeft();
  }
  else {
    stopMotors();
  }
}

void setup() {

  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  stopMotors();

  WiFi.mode(WIFI_STA);

  esp_now_init();

  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
}