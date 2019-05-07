<<<<<<< Updated upstream:ExternalWakeUp.ino

/*
Deep Sleep with External Wake Up
=====================================
This code displays how to use deep sleep with
an external trigger as a wake up source and how
to store data in RTC memory to use it over reboots

NOTE:
======
Only RTC IO can be used as a source for external wake
source. They are pins: 0,2,4,12-15,25-27,32-39.
*/
#include <WiFi.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include "printWakeupReason.h"
#include "mqttconnect.h"

const char* ssid     = "MyAP";
const char* password = "temple123";

const char* mqtt_server = "https://api.twilio.com/2010-04-01";
const char* streamId   = "AC4efcf7c4ba2cbf310deb4aeb5abdc52c";
const char* privateKey = "ce488af9a112086ca5d50f25dc0477b9";

/* create an instance of PubSubClient client */
WiFiClient espClient;
PubSubClient client(espClient);

#define BUTTON_PIN_BITMASK 0x200000000 // 2^33 in hex

RTC_DATA_ATTR int bootCount = 0;

void setup(){
  Serial.begin(115200);
  //Print the wakeup reason for ESP32
  print_wakeup_reason();
  mqttconnect(client);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_33,1); //1 = High, 0 = Low

  //Go to sleep now
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();

}

void loop(){
  //This is not going to be called
}
=======
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#include <EspMQTTClient.h>

/*
Deep Sleep with External Wake Up
=====================================
This code displays how to use deep sleep with
an external trigger as a wake up source and how
to store data in RTC memory to use it over reboots

NOTE:
======
Only RTC IO can be used as a source for external wake
source. They are pins: 0,2,4,12-15,25-27,32-39.
*/
#include <WiFi.h>
#include <SPI.h>
#include <Ethernet.h>

#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include "Esp32MQTTClient.h"

const char* ssid     = "MyAP";
const char* password = "temple123";

const char* mqtt_server = "https://api.twilio.com/2010-04-01";
const char* streamId   = "AC4efcf7c4ba2cbf310deb4aeb5abdc52c";
const char* privateKey = "ce488af9a112086ca5d50f25dc0477b9";

/* create an instance of PubSubClient client */
WiFiClient espClient;
PubSubClient client(espClient);

#define BUTTON_PIN_BITMASK 0x200000000 // 2^33 in hex

RTC_DATA_ATTR int bootCount = 0;

void setup(){
  Serial.begin(115200);
  connect(client);

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_,1); //1 = High, 0 = Low

  //Go to sleep now
  Serial.println("Going to sleep now");
  esp_deep_sleep_start();

}

void loop(){
  //This is not going to be called
}
>>>>>>> Stashed changes:ExternalWakeUp/ExternalWakeUp.ino
