/*
  RoboSoto

  Digital I/O - Bumper Switches

  Uses bumper switches to detect collisions
  and react to obstacles.
*/

#define M1_DIR 13
#define M1_PWM 12

#define M2_DIR 21
#define M2_PWM 14

#define M3_DIR 10
#define M3_PWM 9

#define M4_DIR 11
#define M4_PWM 47

#define LEFT_BUMPER 4
#define RIGHT_BUMPER 5

int speedValue = 120;

void setup() {

  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  pinMode(LEFT_BUMPER, INPUT_PULLUP);
  pinMode(RIGHT_BUMPER, INPUT_PULLUP);

  Serial.begin(115200);
}

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

void loop() {

  bool leftPressed = digitalRead(LEFT_BUMPER) == LOW;
  bool rightPressed = digitalRead(RIGHT_BUMPER) == LOW;

  if (leftPressed || rightPressed) {

    Serial.println("Obstacle Detected");

    stopMotors();
    delay(300);

    moveBackward();
    delay(800);

    stopMotors();
    delay(300);
  }
  else {
    moveForward();
  }
}