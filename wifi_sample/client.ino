#include "WiFiS3.h"

char ssid[] = "arduino";
char pass[] = "password";

WiFiUDP Udp;
IPAddress gatewayIP;

void setup() {
  Serial.begin(9600);

  WiFi.config(IPAddress(192, 168, 0, 2));
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.println("Connecting");
    delay(1000);
  }

  Serial.println("Connected");
  Serial.println(WiFi.localIP());

  gatewayIP = WiFi.gatewayIP();

  Udp.begin(2390);
}

void loop() {
  Udp.beginPacket(gatewayIP, 2390);
  Udp.print("Hello world!");
  Udp.endPacket();

  delay(1000);
}
