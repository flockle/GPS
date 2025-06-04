#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Create GPS object
TinyGPSPlus gps;

// Define software serial pins for GPS module
SoftwareSerial gpsSerial(4, 3); // RX = 4, TX = 3

void setup() {
  Serial.begin(9600);       // Serial monitor
  gpsSerial.begin(9600);    // GPS module
  Serial.println("GPS Module Reading...");
}

void loop() {
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
    
    if (gps.location.isUpdated()) {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);
      Serial.println("--------");
    }
  }
}
