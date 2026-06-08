# RoboSoto

![RoboSoto](Robot%20Images/Final-RoboSoto.png)

## Overview
RoboSoto is a robot car built using a Romeo ESP32-S3 controller. The project basically evolved from a simple remote-controlled robot into an autonomous platform capable of obstacle avoidance, light tracking, and IMU-based navigation.

RoboSoto is a robot car built using a Romeo ESP32-S3 controller. The project basically evolved from a simple code coltrolled to light controoled then to a remote-controlled robot, it is capable of obstacle avoidance, light tracking, wireless communication, and IMU-based navigation. Through the whole project, I continued to add new hardware and software systems to expand the robot's capabilities and improve its performance.
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
The first stage of RoboSoto focused on building a functioal robot. The chassis, motors, battery system, and Romeo ESP32-S3 controller were assembled and connected together. During this stage, the main goal was to create a working four-wheel drive platform/chassy that could move forward, backward, and turn. This provided foundation/base for all future upgrades.

![Original Robot](Robot%20Images/OrigionalVersion-V1.png)

---

### Stage 2 - Figure 8 Navigation
One of the first challenges was programming the robot to complete a figure-8 course. The Goal was to go around the figure-8 without touhing any of the obstacles. I used different movement patterns and motor tuning to test and create smooth turns and consistent driving behavior. This challenge introduced path planning concepts and showed how software alone could control such a complex robot's movement.

![Figure 8](Robot%20Images/Figure8.png)

---

### Stage 3- Buttons and Light Tracking
Next I added bumper switches to let the robot detect collisions and react to obstacles, Once that was completed I added a photoresistor so the robot could measure light intensity and follow a light source. These changes helped the robot interact with its surroundings instead of just following pre-programmed commands.

![Buttons and Light Sensor](Robot%20Images/Buttons_light.png)

---

### Stage 4- Chassis Improvements
The robot chassis was redesigned and reorganized to make it much smaller then the origional one and to add another layer, and the components were moved around to improve reliability, simplify wiring, and make future upgrades easier. This basically focused on improving the overall design and making the robot more practical for long-term development.

![Top View](Robot%20Images/OrigionalVersionTop-V1.png)

---

### Stage 5 - Wireless Controller
Next a wireless controller was added using a FireBeetle ESP32 and ESP-NOW communication. This allowed the RoboSoto to be controlled remotely with buttons or a Joystick and without cables. I first used Multiple buttons then switched to a Joystick to send movement commands to the robot, providing responsive real-time control and showing wireless communication between two microcontrollers.

![Controller](Robot%20Images/Wireless.png)

---

### Stage 6- IMU Integration
Finally a BNO055 Inertial Measurement Unit (IMU) was added to provide heading and make perfect turns with the robots. The IMU was mounted securely to the robot and programmed using the Adafruit BNO055 library. By reading orientation data directly from the sensor, RoboSoto could determine its position and heading without relying on timed movements, and could make perfect angled turns.

Using the BNO055 sensor, the robot was programmed to do navigation tasks. The robot successfully made a square shape outline with perfect turns and movement using 90-degree turns and later completed a figure-8 course using only IMU feedback. This showed closed-loop control and showed how sensor data can be used to guide robot movement in real time.

![IMU Setup](Robot%20Images/Imu.png)

---

### Final Version
The completed RoboSoto Robot combines multiple robotics concepts into a single robot. It includes wireless control, sensor integration, autonomous behaviors, and IMU-based navigation. The project shows the progression from a basic robot to a more advanced autonomous robotics platform.

![Final RoboSoto](Robot%20Images/Final-RoboSoto.png)

## Videos

### IMU Navigation
These tests show the robot using the BNO055 IMU and a Joystick to control/navigation the robot.

IMU Navigation Test 1: https://youtu.be/__rwe6rxlLk
IMU Navigation Test 2: https://youtu.be/I40j0DHA2YQ

### Figure 8 Navigation
This test shows the robot successfully completing the figure-8 course.

Figure 8 Test: https://youtu.be/x2vdAb9sFck

## Software
- Arduino IDE
- ESP-NOW
- Adafruit BNO055 Library

## Future Improvements
- Computer vision
- Autonomous mapping
- GPS navigation
- Path planning