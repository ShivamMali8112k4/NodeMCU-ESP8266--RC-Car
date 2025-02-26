# 📖 Working of NodeMCU Remote Controlled Car  

## Overview  
This project allows you to control a **4-motor remote-controlled car** using a **NodeMCU (ESP8266)** via **Wi-Fi**. It receives commands through a **web interface** and moves accordingly.

## Working Principle ⚙️  

1. **Wi-Fi Connectivity**  
   - The NodeMCU connects to a Wi-Fi network using the provided SSID and password.  
   - It starts a **web server** that listens for HTTP requests.  

2. **Receiving Commands**  
   - The car responds to **URL-based commands** sent from a web browser or mobile app.  
   - Example commands:  
     ```
     /F  -> Move Forward  
     /B  -> Move Backward  
     /L  -> Turn Left  
     /R  -> Turn Right  
     /S  -> Stop  
     /SPEED?value=150  -> Set Speed (0-255)  
     ```

3. **Motor Control**  
   - The **L298N motor driver** controls the **4 motors** using digital signals from the NodeMCU.  
   - **PWM (Pulse Width Modulation)** is used to control the motor speed.  

4. **Speed Adjustment**  
   - The speed is adjusted dynamically by modifying the **PWM values** sent to the motor driver.  
   - The speed range is **0 (stop) to 255 (full speed)**.  

## Web Server Response 🌐  
When a request is received, the NodeMCU:  
1. Executes the corresponding motor action.  
2. Sends a basic **HTML response** displaying the current speed.  

## Mobile App Control 📲  
- You can use the **"ESP8266 WiFi Robot Car"** app from the Play Store for an easier control interface.  

## Future Enhancements 🔮  
- 🚀 Obstacle avoidance with an ultrasonic sensor.  
- 🎯 Fine-tuned speed control for better movement.  
- 📡 Bluetooth control option for offline use.  


Now, your car can go beyond just basic control — the possibilities are endless! 🚀
