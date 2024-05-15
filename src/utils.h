#ifndef UTILS_h
#define UTILS_h

#include "smoles.h"

class JSONUtil {
public:
    static StaticJsonDocument<200> createJsonObject(const char* key, float value);
};

#endif
