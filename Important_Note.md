# 📝 Notes & Troubleshooting  

## Important Notes ⚠️  
- Ensure that the **Wi-Fi credentials** in the code are correct.  
- Check the **serial monitor** for the IP address assigned to the NodeMCU.  
- The power supply should be **sufficient** for the motors (preferably 9V or 12V).  

## Common Issues & Fixes 🔧  

### ❌ Wi-Fi Not Connecting  
**Issue**: The NodeMCU keeps printing "Connecting to WiFi..."  
**Solution**:  
- Double-check your **Wi-Fi SSID & password**.  
- Ensure that your **Wi-Fi network is 2.4GHz** (ESP8266 does not support 5GHz).  

### ❌ Motors Not Moving  
**Issue**: The car does not respond to commands.  
**Solution**:  
- Check the **wiring of the L298N motor driver**.  
- Verify that the **motor driver is receiving power**.  
- Make sure the **NodeMCU pins are correctly assigned** in the code.  

### ❌ Car Moves Incorrectly  
**Issue**: The car turns in the wrong direction or behaves unexpectedly.  
**Solution**:  
- Swap the **motor connections** in the L298N driver.  
- Modify the **motor control logic** in the code if needed.  

### ❌ Speed Control Not Working  
**Issue**: Changing the speed value does not affect motor speed.  
**Solution**:  
- Check if the **PWM pins (ENA, ENB) are correctly wired**.  
- Ensure `analogWrite()` is used correctly in the code.    
