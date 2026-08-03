/*
  RoboSoto

  Wireless Joystick Control - Sender

  Uses ESP-NOW communication and a joystick
  to remotely drive the robot.
*/

#include <esp_now.h>
#include <WiFi.h>

// Robot MAC Address
uint8_t receiverMAC[] = {0x74, 0x4D, 0xBD, 0x82, 0x09, 0x8C};

#define VRX A0
#define VRY A1
#define SW  2

typedef struct {
  int x;
  int y;
  bool btn;
} JoystickData;

JoystickData data;
esp_now_peer_info_t peerInfo;

void setup() {

  Serial.begin(115200);

  pinMode(SW, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);

  esp_now_init();

  memset(&peerInfo, 0, sizeof(peerInfo));

  memcpy(peerInfo.peer_addr, receiverMAC, 6);

  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  esp_now_add_peer(&peerInfo);
}

void loop() {

  data.x = analogRead(VRX);
  data.y = analogRead(VRY);

  data.btn = (digitalRead(SW) == LOW);

  esp_now_send(receiverMAC,
               (uint8_t *)&data,
               sizeof(data));

  delay(50);
}