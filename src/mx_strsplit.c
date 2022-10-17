#include "libmx.h"

char** mx_strsplit(char const* s, char c) {
    int count = mx_count_words(s, c);
    char** res = (char**)malloc(count);
    int index = 0;
    for (int i = 0; i < count; i++) {
        int size = 0;
        int begin = 0;
        for (;; index++) {
            if (s[index] != c) {
                size++;
                if (begin == 0) begin = index;
            } 
            else if (size && s[index] == c) break;
        }
        res[i] = mx_strnew(size);
        for (int pos = 0; begin < index; pos++) {
            res[i][pos] = s[begin];
            begin++;
        }
        res[i][mx_strlen(res[i])] = '\0';
    }
    return res;
}

