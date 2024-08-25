#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  Serial.println("done");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Start scan");
  int n = WiFi.scanNetworks();

  if (n == 0)
  {
    Serial.println("no wifi found");
  }

  else
  {
    Serial.println("found: " + String(n) + " wifi");
    for(int i = 0; i < n; i++)
    {
      Serial.println(String(i+1) + ":" + WiFi.SSID(i) +"(" + WiFi.RSSI(i) + ")");
    }
  }
  delay(5000);
  Serial.println();
}
