#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

// Define Motor Control Pins (L298N - 4 motors)
#define IN1 D1    // Motor 1 - IN1 (Left Front)
#define IN2 D2    // Motor 1 - IN2 (Left Front)
#define IN3 D3    // Motor 2 - IN3 (Left Rear)
#define IN4 D4    // Motor 2 - IN4 (Left Rear)
#define IN5 D7    // Motor 3 - IN5 (Right Front)
#define IN6 D8    // Motor 3 - IN6 (Right Front)
#define IN7 D0    // Motor 4 - IN7 (Right Rear)
#define IN8 D1    // Motor 4 - IN8 (Right Rear)
#define ENA D5    // PWM for Motor 1 (Speed)
#define ENB D6    // PWM for Motor 2 (Speed)

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi, IP address: ");
  Serial.println(WiFi.localIP());

  // Web server routes
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>4-Motor RC Car Control</h1>";
    html += "<button onclick=\"location.href='/forward'\">Forward</button><br><br>";
    html += "<button onclick=\"location.href='/backward'\">Backward</button><br><br>";
    html += "<button onclick=\"location.href='/left'\">Left</button><br><br>";
    html += "<button onclick=\"location.href='/right'\">Right</button><br><br>";
    html += "<button onclick=\"location.href='/stop'\">Stop</button><br><br>";
    html += "<h3>Motor Speed (0-255)</h3>";
    html += "<input type='range' id='speedSlider' min='0' max='255' value='255' onchange='updateSpeed(this.value)'><br>";
    html += "<script>";
    html += "function updateSpeed(val) {";
    html += "  fetch('/setSpeed?value=' + val);";
    html += "}";
    html += "</script>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Set motor speed
  server.on("/setSpeed", HTTP_GET, [](AsyncWebServerRequest *request){
    String speedStr = request->getParam("value")->value();
    int speed = speedStr.toInt();
    analogWrite(ENA, speed); 
    analogWrite(ENB, speed); 
    request->send(200, "text/html", "Speed Set: " + String(speed) + "<br><br><a href='/'>Back</a>");
  });

  // Car Movement Routes
  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
    forward();
    request->send(200, "text/html", "Moving Forward <br><br><a href='/'>Back</a>");
  });

  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
    backward();
    request->send(200, "text/html", "Moving Backward <br><br><a href='/'>Back</a>");
  });

  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request){
    left();
    request->send(200, "text/html", "Turning Left <br><br><a href='/'>Back</a>");
  });

  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request){
    right();
    request->send(200, "text/html", "Turning Right <br><br><a href='/'>Back</a>");
  });

  server.on("/stop", HTTP_GET, [](AsyncWebServerRequest *request){
    stop();
    request->send(200, "text/html", "Stopped <br><br><a href='/'>Back</a>");
  });

  server.begin();
}

void loop() {
  // Server handles all actions
}

void forward() {
  // Forward movement: both left and right motors go forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

void backward() {
  // Backward movement: both left and right motors go backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

void left() {
  // Left movement: left motors go backward, right motors go forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
}

void right() {
  // Right movement: right motors go backward, left motors go forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
}

void stop() {
  // Stop: all motors stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}
