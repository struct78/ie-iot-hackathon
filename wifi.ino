void connectToWifi() {
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
  }

  while (status != WL_CONNECTED) {
    Serial.print("Connecting to WiFi: ");
    Serial.println(WIFI_SSID);
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);

    for (int x = 0 ; x < 20 ; x++) {
      if (x % 2 == 0) {
        turnOnLED();
      } else {
        turnOffLED();
      }
      delay(500);
    }
  }
  
  Serial.println("Connected to wifi");
}
