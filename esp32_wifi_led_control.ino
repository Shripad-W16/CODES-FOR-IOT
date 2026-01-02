#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiServer server(80);
const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');

  if (request.indexOf("/ON") != -1)
    digitalWrite(ledPin, HIGH);
  if (request.indexOf("/OFF") != -1)
    digitalWrite(ledPin, LOW);

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html\n");
  client.println("LED Control");

  client.stop();
}
