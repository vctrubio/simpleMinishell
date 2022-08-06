#include "../../includes/memory.h"
#include <stdio.h>

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

	// static int i = 0;
	// printf("check %d\n", i++);
	node = check_pointer(malloc(sizeof(t_node_malloc)));
	node->size = __size;
	// printf("%zu SIZE--\n\n", node->size);
	node->prev = NULL;
	node->next = NULL;
	_memory_add(node);
	node->ptr = check_pointer(malloc(__size));
	return (node->ptr);
}
