#include "../../includes/memory.h"

void *check_pointer(void *ptr)
{
	if (!ptr)
	{
		_memory().free_all();
		exit(write(2, "error _memory_malloc", 21));
	}
	return (ptr);
}

void *_memory_malloc(size_t __size)
{
	t_node_malloc *node;

	node = check_pointer(malloc(sizeof(t_node_malloc)));
	node->size = __size;
	node->prev = NULL;
	node->next = NULL;
	_memory_add(node);
	node->ptr = check_pointer(malloc(__size));
	return (node->ptr);
}
