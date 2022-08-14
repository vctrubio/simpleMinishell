#include "../../includes/memory.h"

void _memory_add(t_node_malloc *malloc)
{
	t_node_malloc **list;

	list = _memory_list();
	if (!*list)
		*list = malloc;
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = malloc;
		malloc->prev = *list;
	}
}
