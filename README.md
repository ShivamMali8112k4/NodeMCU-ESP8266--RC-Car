# 🚗 NodeMCU Remote Controlled Car 🚗

This project is a **remote-controlled car** powered by **NodeMCU (ESP8266)** and controlled via a **web interface**. The car uses the **L298N motor driver** to control **4 motors**, allowing for movement in all directions, as well as speed control via PWM.

## Features ✨

- **4-Motor Control**: Control each of the 4 motors (left front, left rear, right front, right rear) independently. 
- **Web Interface**: Control the car using a simple web page hosted on the NodeMCU. 🌐
- **Speed Control**: Adjust the speed of the motors using a slider on the web page. ⚡
- **Wi-Fi Connectivity**: Connects to Wi-Fi and can be controlled from anywhere in the network. 📶

## Components Required 🛠️

- **NodeMCU (ESP8266)** 🧩
- **L298N Motor Driver** 🏎️
- **4 DC Motors** ⚙️
- **Power Supply (for motors)** 🔋
- **Jumper wires** 🔌
- **Breadboard (optional)** 🧑‍🔧
- **Smartphone, tablet, or PC for control** 📱💻

## Pin Mapping 📍

| Component           | Pin (NodeMCU) |
|--------------------|--------------|
| Motor 1 - IN1     | D0           |
| Motor 1 - IN2     | D1           |
| Motor 2 - IN3     | D2           |
| Motor 2 - IN4     | D3           |
| Motor 3 - IN5     | D4           |
| Motor 3 - IN6     | D7           |
| Motor 4 - IN7     | D8           |
| Motor 4 - IN8     | RX           |
| Motor  Speed (ENA) | D5        |
| Motor Speed (ENB) | D6        |

## Installation & Setup 🚀

1. **Install Arduino IDE** and add the **ESP8266 Board** via **Board Manager**.
2. **Install Required Libraries**:
   ```cpp
   #include <ESP8266WiFi.h>


By keeping these points in mind, you'll be able to have a smooth experience with the **NodeMCU 4-Motor Remote Controlled Car**. 🚗💨

Happy coding and building! 😊
