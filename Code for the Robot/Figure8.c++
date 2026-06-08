/*
  RoboSoto

  Basic Figure 8 Navigation

  Uses timed motor control to drive in a figure-8
  pattern without using sensors or IMU feedback.
*/

#define M1_DIR 13
#define M1_PWM 12

#define M2_DIR 21
#define M2_PWM 14

#define M3_DIR 10
#define M3_PWM 9

#define M4_DIR 11
#define M4_PWM 47

int outerSpeed = 120;
int innerSpeed = 70;

void setup() {

  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);

  delay(3000);
}

void stopMotors() {
  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}

void leftCircle() {

  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, innerSpeed);

  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, outerSpeed);

  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, innerSpeed);

  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, outerSpeed);
}

void rightCircle() {

  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, outerSpeed);

  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, innerSpeed);

  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, outerSpeed);

  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, innerSpeed);
}

void forward() {

  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, outerSpeed);

  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, outerSpeed);

  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, outerSpeed);

  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, outerSpeed);
}

void loop() {

  // Left loop
  leftCircle();
  delay(3500);

  stopMotors();
  delay(300);

  // Cross center
  forward();
  delay(1200);

  stopMotors();
  delay(300);

  // Right loop
  rightCircle();
  delay(3500);

  stopMotors();

  while(true);
}