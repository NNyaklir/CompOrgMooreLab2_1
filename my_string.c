#include "my_string.h"

size_t str_len(const char *s)
{
    size_t count = 0;
    char *point = s; // copies the pointer
    // while whats pointed to by point isn't the end of the string increase count 
    while(*point != 0){
        count++;
        point++;
    }
    return count;
}