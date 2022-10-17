#include "libmx.h"

int mx_count_substr(const char* str, const char* sub) {
    int count = 0;

    while (*str) {
        if (str == mx_strchr(str, sub[0])) {
            if (mx_strncmp(str, sub, mx_strlen(sub)) == 0) {
                count++;
            }
        }
        str++;
    }
    return count;
}

