#include <stdio.h>
#include "error_codes.h"

char* error_to_string (int error) {
    switch (error) {
        case OK: return "OK";
        case MALLOC_FAILURE: return "MALLOC_FAILURE";
        case OUT_OF_BOUNDS: return "OUT_OF_BOUNDS";
        default: {
            static char buf[32];
            snprintf(buf, sizeof(buf), "UNKNOWN_ERROR: %d", error);
            return buf;
        }
    }
}
