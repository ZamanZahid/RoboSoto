<div align="center">

# RoboSoto - Made by: Zaman Zahid

<img src="Robot%20Images/Final-RoboSoto.png" width="450">

### Romeo ESP32-S3 Robotics Platform

Wireless Control • Light Tracking • Obstacle Avoidance • IMU Navigation

</div>

## Overview

RoboSoto is a robot car built using a Romeo ESP32-S3 controller. The project evolved from a simple code-controlled robot into a light-tracking, wireless-controlled, and autonomous robotics platform capable of obstacle avoidance, light tracking, wireless communication, and IMU-based navigation.

Throughout the project, I continuously added new hardware and software systems to expand the robot's capabilities and improve its performance.

## Features

* Wireless ESP-NOW control
* Four-wheel drive platform
* Bumper collision detection
* Autonomous obstacle avoidance
* Light tracking with photoresistor
* BNO055 IMU navigation
* IMU square driving
* IMU figure-8 navigation

## Hardware

* Romeo ESP32-S3
* FireBeetle ESP32
* BNO055 IMU
* Photoresistor
* Bumper switches
* 4 DC motors
* Battery pack

## Development Timeline

### Stage 0 - Project Planning and Prototype

<div align="center">
<img src="Robot%20Images/Firstimg.png" width="350">
</div>

Before the RoboSoto was built, the project started with research, planning, and gathering components. I thought about different design ideas, including how many wheels the robot could have, how it could be controlled, the size, and upgraded throughout development. During this stage I collected the needed hardware, including the motors, battery system, board, and controllers.

An initial prototype was made to test component compatibility, motor placement, and overall functionality. This helped me find design limitations early and provided a timeline/roadmap for future development.
---

### Stage 1 - Original Robot Build

<div align="center">
<img src="Robot%20Images/OrigionalVersion-V1.png" width="350">
</div>

With the planning phase done, the first full chassis was made. The motors, wheels, battery system, and Romeo ESP32-S3 controller were mounted and wired together to create a functional four-wheel drive platform.

The goal of this stage was to create a strong and reliable foundation that would be capable of simple movement, including driving forward, backward, and turning. This chassis served as the starting point for all upgrades for the future and gave the physical platform that RoboSoto would continue to evolve from throughout the project.
---

### Stage 2 - Figure 8 Navigation

<div align="center">
<img src="Robot%20Images/Figure8.png" width="350">
</div>

One of the first challenges was programming the robot to complete a figure-8 course. The goal was to navigate the entire course without touching any obstacles. Different movement patterns and motor tuning were tested to create smooth turns and consistent driving behavior. This challenge introduced path-planning concepts and showed how software alone could control complex robot movement.

---

### Stage 3 - Buttons and Light Tracking

<div align="center">
<img src="Robot%20Images/Buttons_light.png" width="350">
</div>

Next, bumper switches were added to allow the robot to detect collisions and react to obstacles. Once that was completed, a photoresistor was added so the robot could measure light intensity and follow a light source. These additions helped RoboSoto interact with its surroundings instead of simply following pre-programmed commands.

---

### Stage 4 - Chassis Improvements

<div align="center">
<img src="Robot%20Images/OrigionalVersionTop-V1.png" width="350">
</div>

The robot chassis was redesigned and reorganized to make it smaller and more compact than the original version. A second layer was added, and components were repositioned to improve reliability, simplify wiring, and make future upgrades easier. This stage focused on improving the overall design and creating a cleaner, more practical robot platform.

---

### Stage 5 - Wireless Controller

<div align="center">
<img src="Robot%20Images/Wireless.png" width="350">
</div>

A wireless controller was added using a FireBeetle ESP32 and ESP-NOW communication. This allowed RoboSoto to be controlled remotely without cables. The project began with multiple buttons for movement control and later transitioned to a joystick system. This provided responsive real-time control while demonstrating wireless communication between two microcontrollers.

---

### Stage 6 - IMU Integration

<div align="center">
<img src="Robot%20Images/Imu.png" width="350">
</div>

Finally, a BNO055 Inertial Measurement Unit (IMU) was added to provide heading and orientation data. The IMU was securely mounted to the robot and programmed using the Adafruit BNO055 library. By reading orientation data directly from the sensor, RoboSoto could determine its position and heading without relying on timed movements.

Using the BNO055 sensor, the robot was programmed to perform navigation tasks. RoboSoto successfully completed square-driving challenges using precise 90-degree turns and later completed a figure-8 course using only IMU feedback. This demonstrated closed-loop control and showed how sensor data can guide robot movement in real time.

---

### Final Version

<div align="center">
<img src="Robot%20Images/Final-RoboSoto.png" width="450">
</div>

The completed RoboSoto combines multiple robotics concepts into a single platform. It includes wireless control, sensor integration, autonomous behaviors, and IMU-based navigation. The project demonstrates the progression from a basic robot to a more advanced autonomous robotics platform.

## Videos

### IMU Navigation

These tests shows the robot using the BNO055 IMU and a Joystick to control/navigation the robot with precise turns.

* IMU Navigation Test 1: https://youtu.be/__rwe6rxlLk
* IMU Navigation Test 2: https://youtu.be/I40j0DHA2YQ

### Figure 8 Navigation

This test shows the robot successfully completing the figure-8 navigation.

* Figure 8 Test: https://youtu.be/x2vdAb9sFck

## Software

* Arduino IDE
* ESP-NOW
* Adafruit BNO055 Library

## Future Improvements

* Computer Vision
* Autonomous Mapping
* GPS Navigation
* Path Planning
* Object Detection
* Autonomous Route Planning
