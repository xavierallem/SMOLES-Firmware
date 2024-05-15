#include "utils.h"

StaticJsonDocument<200> JSONUtil::createJsonObject(const char* key, float value) {
    StaticJsonDocument<200> doc;
    doc[key] = value;
    return doc;
}
