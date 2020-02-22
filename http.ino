void sendData() {
  turnOnLED();
  HttpClient client = HttpClient(wifi, server, port);
  String contentType = "application/json";
  String postData = "{\"value1\":\"";
  postData += outputAir;
  postData += ",";
  postData += outputSound;
  postData += ",";
  postData += outputMotion;
  postData += ",";
  postData += outputLight;
  postData += ",";
  postData += sensor;
  postData += "\"}";
  
  Serial.println(postData);
  String url = "/trigger/sample/with/key/";
  url += IFTTT_KEY;

  client.post(url, contentType, postData);

  int statusCode = client.responseStatusCode();
  String response = client.responseBody();
  Serial.println(response);
  client.stop();
  turnOffLED();
}
