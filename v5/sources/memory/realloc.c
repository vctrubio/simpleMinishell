#include "../../includes/memory.h"

void *_memory_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (!size)
        return (NULL);
    new_ptr = _memory().calloc(1, size);
    if (!new_ptr)
        return (new_ptr);
    _memory().copy(new_ptr, ptr, size);
    _memory().free(ptr);
    return (new_ptr);
}