#include "../../includes/env.h"

void _env_add(t_node_env *malloc)
{
	t_node_env **list;

	list = _env().list();
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
