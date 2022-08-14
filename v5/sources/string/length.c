#include "../../includes/string.h"

size_t _string_length(char *string)
{
    size_t length;

    length = 0;
    if (string)
        while (string[length])
            ++length;
    return (length);
}
