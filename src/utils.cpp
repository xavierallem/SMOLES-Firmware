#include "utils.h"

JsonDocument JSONUtil::createJsonObject(const char* key, float value) {
    JsonDocument doc;
    doc[key] = value;
    return doc;
}
