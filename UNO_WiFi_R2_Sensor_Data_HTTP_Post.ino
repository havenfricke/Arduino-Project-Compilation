#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>

char ssid[] = "iPhone";
char pass[] = "pass123$";

const char server[] = "aws-production.onrender.com";
const int port = 443;
const char urlPath[] = "/data";

WiFiSSLClient net;
HttpClient client(net, server, port);

void connectWiFi() {
  Serial.print("Connecting");
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.println(WiFi.localIP());
}

void loopPost() {
  const char* deviceId = "sensor-1";
  float value = 21.5;

  char body[128];
  snprintf(body, sizeof(body),
           "{\"device_id\":\"%s\",\"data_value\":%.2f}",
           deviceId, value);

  client.beginRequest();
  client.post(urlPath);
  client.sendHeader("Content-Type", "application/json");
  client.sendHeader("Content-Length", (int)strlen(body));
  client.beginBody();
  client.print(body);
  client.endRequest();

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("Status: ");
  Serial.println(statusCode);
  Serial.println(response);

  client.stop();
}

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  connectWiFi();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connectWiFi();
  loopPost();
  delay(60000);
}
