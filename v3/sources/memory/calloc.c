#include "../../includes/memory.h"

void *_memory_calloc(size_t count, size_t size)
{
    void *temp;

    temp = _memory().malloc(count * size);
    if (!temp)
        return (NULL);
    (_memory().set)(temp, '\0', count * size);
    return (temp);
}