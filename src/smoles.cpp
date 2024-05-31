#include "CD74HC4067.h"
#include "utils.h"

CD74HC4067 mux(2, 3, 4, 5); // Actual Pins

void Smoles::setup() {
    Serial.begin(115200);
}

void Smoles::loop() {
    for (int i = 0; i < 16; i++) {
        mux.setChannel(i);
        int value = analogRead(A0); // Analogue Pin for reading
        StaticJsonDocument<200> doc = JSONUtil::createJsonObject("sensor", value);
        serializeJson(doc, Serial);
        Serial.println();
    }
    delay(1000);
}
