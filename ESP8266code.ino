#include <ESP8266WiFi.h>

const char *ssid = "YOUR_WIFI_SSID";  
const char *password = "YOUR_WIFI_PASSWORD";  

WiFiServer server(80);

int speedValue = 150; // Default speed (0-255)

// Common Speed Control Pins
#define ENA D5  // Speed for Left Motors (Both Front & Rear)
#define ENB D6  // Speed for Right Motors (Both Front & Rear)

// Motor Driver 1 (Front Motors)
#define IN1A D1  
#define IN2A D2  
#define IN3A D3  
#define IN4A D4  

// Motor Driver 2 (Rear Motors)
#define IN1B D7  
#define IN2B D8  
#define IN3B D9  
#define IN4B D10  

void setup() {
    Serial.begin(115200);

    // Setup Motor Pins
    pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
    pinMode(IN1A, OUTPUT); pinMode(IN2A, OUTPUT);
    pinMode(IN3A, OUTPUT); pinMode(IN4A, OUTPUT);
    pinMode(IN1B, OUTPUT); pinMode(IN2B, OUTPUT);
    pinMode(IN3B, OUTPUT); pinMode(IN4B, OUTPUT);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.begin();
}

void moveCar(String command) {
    if (command == "F") {  // Forward
        digitalWrite(IN1A, HIGH); digitalWrite(IN2A, LOW);
        digitalWrite(IN3A, HIGH); digitalWrite(IN4A, LOW);
        digitalWrite(IN1B, HIGH); digitalWrite(IN2B, LOW);
        digitalWrite(IN3B, HIGH); digitalWrite(IN4B, LOW);
        analogWrite(ENA, speedValue);  
        analogWrite(ENB, speedValue);  
    } 
    else if (command == "B") {  // Backward
        digitalWrite(IN1A, LOW); digitalWrite(IN2A, HIGH);
        digitalWrite(IN3A, LOW); digitalWrite(IN4A, HIGH);
        digitalWrite(IN1B, LOW); digitalWrite(IN2B, HIGH);
        digitalWrite(IN3B, LOW); digitalWrite(IN4B, HIGH);
        analogWrite(ENA, speedValue);  
        analogWrite(ENB, speedValue);  
    } 
    else if (command == "L") {  // Left Turn
        digitalWrite(IN1A, LOW); digitalWrite(IN2A, HIGH);
        digitalWrite(IN3A, HIGH); digitalWrite(IN4A, LOW);
        digitalWrite(IN1B, LOW); digitalWrite(IN2B, HIGH);
        digitalWrite(IN3B, HIGH); digitalWrite(IN4B, LOW);
        analogWrite(ENA, speedValue / 2);  
        analogWrite(ENB, speedValue);  
    } 
    else if (command == "R") {  // Right Turn
        digitalWrite(IN1A, HIGH); digitalWrite(IN2A, LOW);
        digitalWrite(IN3A, LOW); digitalWrite(IN4A, HIGH);
        digitalWrite(IN1B, HIGH); digitalWrite(IN2B, LOW);
        digitalWrite(IN3B, LOW); digitalWrite(IN4B, HIGH);
        analogWrite(ENA, speedValue);  
        analogWrite(ENB, speedValue / 2);  
    } 
    else if (command == "S") {  // Stop
        digitalWrite(IN1A, LOW); digitalWrite(IN2A, LOW);
        digitalWrite(IN3A, LOW); digitalWrite(IN4A, LOW);
        digitalWrite(IN1B, LOW); digitalWrite(IN2B, LOW);
        digitalWrite(IN3B, LOW); digitalWrite(IN4B, LOW);
        analogWrite(ENA, 0);  
        analogWrite(ENB, 0);  
    }
}

void setSpeed(int value) {
    speedValue = constrain(value, 0, 255); // Ensure speed is within range
    Serial.print("Speed Set to: ");
    Serial.println(speedValue);
}

void loop() {
    WiFiClient client = server.available();
    if (!client) return;

    String request = client.readStringUntil('\r');
    client.flush();

    Serial.println("Request: " + request);

    if (request.indexOf("/F") != -1) moveCar("F");
    else if (request.indexOf("/B") != -1) moveCar("B");
    else if (request.indexOf("/L") != -1) moveCar("L");
    else if (request.indexOf("/R") != -1) moveCar("R");
    else if (request.indexOf("/S") != -1) moveCar("S");
    else if (request.indexOf("/SPEED?value=") != -1) {
        int start = request.indexOf("/SPEED?value=") + 13;
        int end = request.indexOf(" ", start);
        String speedStr = request.substring(start, end);
        setSpeed(speedStr.toInt());
    }

    // Send Response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body>");
    client.println("<h1>ESP8266 Car Control</h1>");
    client.println("<p>Speed: " + String(speedValue) + "</p>");
    client.println("</body></html>");
    client.stop();
}
