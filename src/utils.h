#ifndef UTILS_h
#define UTILS_h

#include "smoles.h"

#include <TimeLib.h>


class JSONUtil {
public:
    static JsonDocument createJsonObject(const char* key, float value);
};

#endif


class TimeUtil {
    public:
        static String getTime(unsigned long timestamp);



};
