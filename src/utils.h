#ifndef UTILS_h
#define UTILS_h

#include "smoles.h"

class JSONUtil {
public:
    static JsonDocument createJsonObject(const char* key, float value);
};

#endif
