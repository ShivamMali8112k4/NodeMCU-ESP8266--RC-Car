# 🚗 NodeMCU Remote Controlled Car 🚗

This project is a **remote-controlled car** powered by **NodeMCU (ESP8266)** and controlled via a **web interface**. The car uses the **L298N motor driver** to control **4 motors**, allowing for movement in all directions, as well as speed control via PWM.

## Features ✨

- **4-Motor Control**: Control each of the 4 motors (left front, left rear, right front, right rear) independently. 
- **Web Interface**: Control the car using a simple web page hosted on the NodeMCU. 🌐
- **Speed Control**: Adjust the speed of the motors using a slider on the web page. ⚡
- **Wi-Fi Connectivity**: Connects to Wi-Fi and can be controlled from anywhere in the network. 📶

## Components Required 🛠️

- NodeMCU (ESP8266) 🧩
- L298N Motor Driver 🏎️
- 4 DC Motors ⚙️
- Power Supply (for motors) 🔋
- Jumper wires 🔌
- Breadboard (optional) 🧑‍🔧
- Smartphone, tablet, or PC for control 📱💻

## Pin Mapping 📍

| Component | Pin (NodeMCU)  |
|-----------|----------------|
| Motor 1 - IN1 | D1             |
| Motor 1 - IN2 | D2             |
| Motor 2 - IN3 | D3             |
| Motor 2 - IN4 | D4             |
| Motor 3 - IN5 | D7             |
| Motor 3 - IN6 | D8             |
| Motor 4 - IN7 | D0             |
| Motor 4 - IN8 | D1             |
| Motor 1 Speed (ENA) | D5       |
| Motor 2 Speed (ENB) | D6       |
