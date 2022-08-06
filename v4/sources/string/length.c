#include "../../includes/string.h"

size_t _string_length(char *string)
{
    if (string && *string)
        return (1 + _string_length(++string));
    return (0);
}
