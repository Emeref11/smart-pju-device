#include "wifipoint.h"

/* Put IP Address details */
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

WebServer server(80);

void initWiFiPoint() {
    WiFi.softAP("XLKM#4 PJU @12", "12345678");
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);

    server.on("/", handle_OnConnect);
    server.onNotFound(handle_NotFound);

    server.begin();
}

void handle_OnConnect() {
    server.send(200, "text/html", SendHTML());
}

void handle_NotFound() {
    server.send(404, "text/plain", "Not found");
}

String SendHTML() {
    String ptr = "<!DOCTYPE html> <html>\n";
    ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
    ptr += "<title>LED Control</title>\n";
    ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
    ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
    ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
    ptr += ".button-on {background-color: #3498db;}\n";
    ptr += ".button-on:active {background-color: #2980b9;}\n";
    ptr += ".button-off {background-color: #34495e;}\n";
    ptr += ".button-off:active {background-color: #2c3e50;}\n";
    ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
    ptr += "</style>\n";
    ptr += "</head>\n";
    ptr += "<body>\n";
    ptr += "<h1>XLMM#4 PJU</h1>\n";
    ptr += "<h3>Using Access Point(AP) Mode for PJU @12</h3>\n";

    ptr += "</body>\n";
    ptr += "</html>\n";
    return ptr;
}