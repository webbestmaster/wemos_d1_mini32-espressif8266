#include <Arduino.h>

const uint8_t TOUCH_PIN = D2;
const long BAUD_RATE = 115200;

bool ledState = false;
bool lastTouch = false;

void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(TOUCH_PIN, INPUT);
    digitalWrite(LED_BUILTIN, HIGH);  // старт с выкл (инверсная логика)
}

void loop() {
    bool touch = digitalRead(TOUCH_PIN) == HIGH;

    if (touch && !lastTouch) {
        ledState = !ledState;
        digitalWrite(LED_BUILTIN, ledState ? LOW : HIGH);
        Serial.println(ledState ? "LED ON" : "LED OFF");
        delay(50);  // защита от дребезга
    }

    lastTouch = touch;
}
