# Smart Streets

This is the code that runs the Smart Streets prototype. The following sensors are used:

* [DFRobot C02 Sensor SEN0159](https://wiki.dfrobot.com/CO2_Sensor_SKU_SEN0159)
* [DFRobot Analog Sound Sensor DFR0034](https://wiki.dfrobot.com/Analog_Sound_Sensor_SKU__DFR0034)
* [Mini PIR Module AS312/AM312](https://unusualelectronics.co.uk/as312-am312-mini-pir-module-review/)
* [Adafruit ALS-PT19 Analog Light Sensor Breakout](https://www.adafruit.com/product/2748)

## Dependencies
For this code to work properly, you will need to create a file called `credentials.h`, in this file you will need to add your WiFi username/password, and your IFTTT webhook key.

```
#define WIFI_SSID "{YOUR_NETWORK_NAME}"
#define WIFI_PASS "{YOUR_NETWORK_PASSWORD}"
#define IFTTT_KEY "{YOUR_WEBHOOK_KEY}"
```