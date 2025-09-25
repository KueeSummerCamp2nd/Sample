#include "WiFiS3.h"

char ssid[] = "arduino";
char pass[] = "password";

WiFiUDP Udp;

void setup() {
  Serial.begin(9600);

  WiFi.config(IPAddress(192, 168, 0, 1));
  WiFi.beginAP(ssid, pass);

  Serial.println("AP started");
  Serial.println(WiFi.localIP());

  Udp.begin(2390);
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    char packetBuffer[255];
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = '\0';
    }
    Serial.println(packetBuffer);
  }
}
