#include <Arduino.h>

void setup() {
    Serial.begin(115200);   // скорость порта
}

void loop() {
    Serial.println("Hello from ESP8266");
    delay(1000);
}
