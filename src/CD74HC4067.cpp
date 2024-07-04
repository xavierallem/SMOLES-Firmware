#include "CD74HC4067.h"
#include "smoles.h"

CD74HC4067::CD74HC4067(int s0, int s1, int s2, int s3, int enable) : _s0(s0), _s1(s1), _s2(s2), _s3(s3),
                                                                     _enable(enable) {
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_s3, OUTPUT);
    pinMode(_enable, OUTPUT);
}

void CD74HC4067::setChannel(int channel) {
    digitalWrite(_enable, HIGH);
    int bit0 = (channel >> 0) & 1;
    digitalWrite(_s0, bit0);
    Serial.print(bit0);
    int bit1 = (channel >> 1) & 1;
    digitalWrite(_s1, bit1);
    Serial.print(bit1);
    int bit2 = (channel >> 2) & 1;
    digitalWrite(_s2, bit2);
    Serial.print(bit2);
    int bit3 = (channel >> 3) & 1;
    digitalWrite(_s3, bit3);
    Serial.print(bit3);
    digitalWrite(_enable, LOW);
    Serial.print(':');
}
