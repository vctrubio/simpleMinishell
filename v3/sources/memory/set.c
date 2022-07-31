#include "../../includes/memory.h"

void *_memory_set(void *pointer, int set, size_t length)
{
    size_t index;

    index = 0;
    if (!pointer)
        return (NULL);
    while (index < length)
        *((unsigned char *)pointer + index++) = (unsigned char)set;
    return (pointer);
}