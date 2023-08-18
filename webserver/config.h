
#ifndef CONFIG_H_  
#define CONFIG_H_


const char* ssid = "MyWiFi_8266";     // Your wireless network name (SSID)
const char* password = "password";    // Your wireless netword password

// ThingSpeak information
const char* web = "https://thingspeak.com/channels/1991175";
char thingSpeakAddress[] = "api.thingspeak.com";
unsigned long channelID = 1991175;
char* writeAPIKey = "xxxxxxxxxxxxxx";
char* readAPIKey = "xxxxxxxxxxxxxxx";
unsigned int postingInterval = 20 * 1000;
unsigned int RSSIField = 1;
unsigned int AirQualityField = 2;
unsigned int CO2Field = 3;
unsigned int TVOCField = 4;

unsigned int CO2FieldThreshold = 1000;
unsigned int TVOCFieldThreshold = 100;

#endif 
