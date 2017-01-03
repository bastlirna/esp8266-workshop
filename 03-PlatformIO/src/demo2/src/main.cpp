#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <hal.h>

HAL hal(INIT_ALL);

WiFiClient espClient;
PubSubClient client(espClient);

#define topicName(a) _topicName((char*)a)
static char* _topicName(char *name)
{
  static char buff[128];
  sprintf(buff, "/workshop/%s/%s", hal.getHostname(), name);
  return buff;
}

static void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

static void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    if (client.connect(hal.getHostname())) { // pripojime se k MQTT serveru
      Serial.println("connected");
      client.publish(topicName("status"), "online");
      client.subscribe(topicName("command"));
    } else {
      Serial.println("failed");
      // Wait 5 seconds before retrying
      delay(2000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  hal.init();
  WiFi.begin("IOT", "iotpass"); // Pripojeni k WiFi essid, password

  Serial.print("Connecting ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("DONE");

  client.setServer("mqtt.sh.cvut.cz", 1883); // Pripojeni k mqtt serveru
  client.setCallback(callback);

  randomSeed(micros());
  Serial.println(WiFi.localIP());
}

void loop()
{
  if (!client.connected()) {
   reconnect();
  }
  client.loop();

}
