#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Redmi Note 13 5G";
const char* password = "jizzz2007";

WebServer server(80); // Create a web server on port 80

void handleroot() {
    server.send(200, "text/plain", "Hello, world!"); // Response to root URL
}
void handleroot_2(){
   server.send(200, "text/plain", "i am jissy");
}
void handleroot_3(){
   server.send(200, "text/plain", "  i am lekshmi");
}
void handleroot_4(){
   server.send(200, "text/plain", "i am nidhi");
}
void handleroot_5(){
   server.send(200, "text/plain", "i am karthika");
}
void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    // Print the IP address once connected
    Serial.print("Connected to WiFi. IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleroot);
    server.on("/2", handleroot_2);
    server.on("/3", handleroot_3); 
    server.on("/4", handleroot_4);
    server.on("/5", handleroot_5);// Handle root request
    server.begin(); // Start the server
}

void loop() {
    server.handleClient(); // Listen for incoming requests
}