#include <ArduinoHttpClient.h>
#include <LiquidCrystal.h>
#include <WiFi.h>
#include "credentials.h"
#define LED_PIN 2
char server[] = "maker.ifttt.com";
int port = 80;
WiFiClient wifi;
float volts;
long outputSound;
long outputAir;
long outputMotion;
long outputLight;
long loops;
int numSensors = 10;
long sensor = 0;
unsigned long startTime;
unsigned long currentTime;
const unsigned long period = 5000;
int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  startTime = millis();
  connectToWifi();
  resetData();
}

void loop()
{
  captureSound();
  captureAir();
  captureMotion();
  captureLight();

  if (currentTime - startTime >= period) {
    calculateData();
    sendData();
    resetData();
    startTime = currentTime;
    sensor++;

    if (sensor > numSensors) {
      sensor = 0;
    }
  }

  loops++;
  currentTime = millis();
}
