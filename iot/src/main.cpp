//MQTT client name
// Set a unique identifier for your device before importing comms.h
const char *mqttClient = "ESP32_jackson"; // EDIT THIS FIELD

const char *mqttTopic;

#include <Arduino.h>
#include "comms.h"

void performActionBasedOnPayload(String payload)
{
    Serial.print("Payload received: ");
    Serial.println(payload);

    // Turn built-in LED ON if payload starts with '1', else OFF
    if (payload.length() > 0 && payload[0] == '1')
    {
        Serial.println("Action: LED ON");
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        Serial.println("Action: LED OFF");
        digitalWrite(LED_BUILTIN, LOW);
    }
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    
    wifiSetup();
    mqttSetup();

    while (!Serial)
    {
        delay(10);
    }
    delay(1000);

    randomSeed(analogRead(A0));
}

void loop()
{
    // 1. Maintain connection to the broker
    mqttConnect();

    int randomNumber = (1, 10001);
    sendPeriodicUpdate("sensorData", String(randomNumber));

    client.loop();
    delay(100);
}