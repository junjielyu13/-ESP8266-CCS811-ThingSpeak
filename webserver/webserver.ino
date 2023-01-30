#include "ESP8266WiFi.h"
#include "ThingSpeak.h"
#include "DFRobot_CCS811.h"
#include "config.h"
#include "web.h"


WiFiClient client;
DFRobot_CCS811 CCS811;


// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;


// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;


int writeTSData(long TSChannel, unsigned int TSField, float data) {
  // Write the data to the channel
  int writeSuccess = ThingSpeak.writeField(TSChannel, TSField, data, writeAPIKey);
  if (writeSuccess == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(writeSuccess));
  }
  return writeSuccess;
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB port only
    delay(1000);
  }

  // Initialize ThingSpeak
  ThingSpeak.begin(client);

  // Wait for the chip to be initialized completely, and then exit
  while (CCS811.begin() != 0) {
    Serial.println("failed to init chip, please check if the chip connection is fine");
    delay(1000);
  }

  delay(2000);
  Serial.println("Setup done");
  Serial.println("start connecting...");


  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients

  if (client) {  // If a new client connects,
    Serial.println("New Client.");
    String currentLine = "";

    currentTime = millis();
    previousTime = currentTime;
    // loop while the client's connected
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {  // if there's bytes to read from the client,
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {  // if the byte is a newline character
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();


            if (header.indexOf("GET /1") >= 0) {

              Serial.println("Scan start");
              int n = WiFi.scanNetworks();

              if (n == 0) {
                Serial.println("no networks found");
              } else {
                for (int i = 0; i < n; i++) {
                  if (WiFi.SSID(i) == "MIWIFI_2G_bPkR") {
                    long rssi = WiFi.RSSI(i);
                    writeTSData(channelID, RSSIField, rssi);
                  }
                  delay(100);
                }
              }
            } else if (header.indexOf("GET /2") >= 0) {
              long airclear = CCS811.readBaseLine();
              writeTSData(channelID, AirQualityField, airclear);
            } else if (header.indexOf("GET /3") >= 0) {
              long co2ppm = CCS811.getCO2PPM();
              writeTSData(channelID, CO2Field, co2ppm);
            } else if (header.indexOf("GET /4") >= 0) {
              long tvocppb = CCS811.getTVOCPPB();
              writeTSData(channelID, TVOCField, tvocppb);
            }

            printWeb(client);


            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";    // Clear the header variable
    client.stop();  // Close the connection
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}