/*
  RoboSoto

  Individual Wheel Test

  Runs each wheel one at a time to verify
  motor wiring and orientation.
*/

#define M1_DIR 13
#define M1_PWM 12

#define M2_DIR 21
#define M2_PWM 14

#define M3_DIR 10
#define M3_PWM 9

#define M4_DIR 11
#define M4_PWM 47

void setup() {

  Serial.begin(115200);

  pinMode(M1_DIR, OUTPUT);
  pinMode(M2_DIR, OUTPUT);
  pinMode(M3_DIR, OUTPUT);
  pinMode(M4_DIR, OUTPUT);

  pinMode(M1_PWM, OUTPUT);
  pinMode(M2_PWM, OUTPUT);
  pinMode(M3_PWM, OUTPUT);
  pinMode(M4_PWM, OUTPUT);
}

void stopAll() {

  analogWrite(M1_PWM, 0);
  analogWrite(M2_PWM, 0);
  analogWrite(M3_PWM, 0);
  analogWrite(M4_PWM, 0);
}

void loop() {

  Serial.println("Motor 1");
  digitalWrite(M1_DIR, HIGH);
  analogWrite(M1_PWM, 120);
  delay(3000);
  stopAll();
  delay(1000);

  Serial.println("Motor 2");
  digitalWrite(M2_DIR, LOW);
  analogWrite(M2_PWM, 120);
  delay(3000);
  stopAll();
  delay(1000);

  Serial.println("Motor 3");
  digitalWrite(M3_DIR, HIGH);
  analogWrite(M3_PWM, 120);
  delay(3000);
  stopAll();
  delay(1000);

  Serial.println("Motor 4");
  digitalWrite(M4_DIR, LOW);
  analogWrite(M4_PWM, 120);
  delay(3000);
  stopAll();

  while(true);
}