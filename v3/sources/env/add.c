#include "../../includes/env.h"

t_node_env **_env_list(void);

void _env_add(t_node_env *malloc)
{
	t_node_env **list;

	list = _env_list();
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
