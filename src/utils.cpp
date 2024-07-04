#include "utils.h"

JsonDocument JSONUtil::createJsonObject(const char* key, float value) {
    JsonDocument doc;
    doc[key] = value;
    return doc;
}



String TimeUtil::getTime(unsigned long timestamp) {
    return String(year(timestamp))+":"+String(month(timestamp))+":"+ String(day(timestamp))+":"+ String(hour(timestamp)) + ":" + String(minute(timestamp)) + ":" + String(second(timestamp));
}