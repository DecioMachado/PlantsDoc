void handleRoot() {
//  char temp[400];
//  int sec = millis() / 1000;
//  int min = sec / 60;
//  int hr = min / 60;
  String json;
  StaticJsonDocument<200> doc;
  doc["name"] = "plantName";
  doc["humidity"] = output_value;
  serializeJson(doc, json);
  server.send(200, "application/json", json);
}

void handleNotFound() {
  String message = "Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}
