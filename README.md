# RoboSoto

![RoboSoto](Robot%20Images/Final-RoboSoto.png)

## Overview
RoboSoto is a robot car built using a Romeo ESP32-S3 controller. The project evolved from a simple remote-controlled robot into an autonomous platform capable of obstacle avoidance, light tracking, and IMU-based navigation.

## Features
- Wireless ESP-NOW control
- Four-wheel drive platform
- Bumper collision detection
- Autonomous obstacle avoidance
- Light tracking with photoresistor
- BNO055 IMU navigation
- IMU square driving
- IMU figure-8 navigation

## Hardware
- Romeo ESP32-S3
- FireBeetle ESP32
- BNO055 IMU
- Photoresistor
- Bumper switches
- 4 DC motors
- Battery pack

## Development Timeline

### Stage 1 - Original Robot Build
The first version of RoboSoto focused on creating a working four-wheel drive platform.

![Original Robot](Robot%20Images/OriginalVersion-V1.png)

---

### Stage 2 - Chassis Improvements
The robot was redesigned and refined to improve wiring, layout, and reliability.

![Top View](Robot%20Images/OriginalVersionTop-V1.png)

---

### Stage 3 - Wireless Controller
A custom ESP-NOW controller was built to drive the robot wirelessly.

![Controller](Robot%20Images/Wireless.png)

---

### Stage 4 - Buttons and Light Tracking
Bumper switches and a photoresistor were added for collision detection and light-following behavior.

![Buttons and Light Sensor](Robot%20Images/Buttons_light.png)

---

### Stage 5 - IMU Integration
A BNO055 IMU was mounted and programmed to track orientation and heading.

![IMU Setup](Robot%20Images/Imu.png)

---

### Stage 6 - Figure 8 Navigation
Using only IMU heading data, RoboSoto completed figure-8 navigation patterns.

![Figure 8](Robot%20Images/Figure8.png)

---

### Final Version
The completed RoboSoto platform combines wireless control and autonomous navigation systems.

![Final RoboSoto](Robot%20Images/Final-RoboSoto.png)

## Videos

### IMU Navigation
[Watch IMU Test](Robot%20Video/Imu.mov)

### Figure 8 Navigation
[Watch Figure 8 Test](Robot%20Video/Figure8.mov)

## Software
- Arduino IDE
- ESP-NOW
- Adafruit BNO055 Library

## Future Improvements
- Computer vision
- Autonomous mapping
- GPS navigation
- Path planning