void captureLight() {
  float value = analogRead(A2);
  float voltage = value * (5.5 / 1023.0);
  float microamps = ( voltage / 10000 ) * 100000;
  float lux = microamps * 2;
  outputLight += lux;
}
