#include <WiFi.h>
 #include <WebServer.h>
 // Network credentials for Access Point mode
 const char* ssid = "ESP32_AP";
 const char* password = "12345678";
 // Web server on port 80
 WebServer server(80);
 int ledPin_1 = 13;
 int ledPin_2 = 12;// GPIO pin connected to the LED
 void handleRoot() {
 // HTML content with buttons to turn on and off the LED
 String html = "<html><body>";
 html += "<h1>Control LED</h1>";
 html += "<button onclick=\"location.href='/on'\">Turn ON</button>";
 html += "<button onclick=\"location.href='/off'\">TurnOFF</button>";
  html += "<button onclick=\"location.href='/on1'\">Turn ON</button>";
 html += "<button onclick=\"location.href='/off1'\">TurnOFF</button>";
 html += "</body></html>";
 
 server.send(200, "text/html", html); // Send the webpage
 }
 void handleLEDOn_1() {
 digitalWrite(ledPin_1, HIGH); // Turn the LED on
 server.sendHeader("Location", "/"); // Redirect to the main page
 server.send(303); // Send HTTP redirect
 }
 void handleLEDOff_1() {
 digitalWrite(ledPin_1, LOW); // Turn the LED off
 server.sendHeader("Location", "/");
 server.send(303);
 }
 void handleLEDOn_2() {
 digitalWrite(ledPin_2, HIGH); // Turn the LED on
 server.sendHeader("Location", "/"); // Redirect to the main page
 server.send(303); // Send HTTP redirect
 }
 void handleLEDOff_2() {
 digitalWrite(ledPin_2, LOW); // Turn the LED off
 server.sendHeader("Location", "/");
 server.send(303);
 }
 void setup() {
 Serial.begin(115200);
 // Setup LED pin as output
 pinMode(ledPin_1, OUTPUT);
 digitalWrite(ledPin_1, LOW);
  pinMode(ledPin_2, OUTPUT);
 digitalWrite(ledPin_2, LOW);
 


 // Set up ESP32 as an access point
 WiFi.softAP(ssid, password);
 // Start web server
 server.on("/", handleRoot);
 server.on("/on", handleLEDOn_1);
 server.on("/off", handleLEDOff_1);
 server.on("/on1", handleLEDOn_2);
 server.on("/off1", handleLEDOff_2);
 server.begin();
 Serial.println("Web server started. Connect to Wi-Fi network:ESP32_AP");
 Serial.println("Access webpage at http://192.168.4.1");
 }
 void loop() 
 {
 server.handleClient(); // Handle web client requestS
 }