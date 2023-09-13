#include <stdio.h>
#include "operation_codes.h"

char* operation_to_string (int operation) {
    switch (operation) {
        case OPERATION_INSERT: return "OPERATION_INSERT";
        case OPERATION_REMOVE: return "OPERATION_REMOVE:";
        case OPERATION_CONTAINS: return "OPERATION_CONTAINS:";
        default: {
            static char buf[32];
            snprintf(buf, sizeof(buf), "UNKNOWN_OPERATION: %d", operation);
            return buf;
        }
    }
}
