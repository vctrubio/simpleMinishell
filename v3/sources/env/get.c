#include "../../includes/env.h"
#include <stdio.h>

t_node_env **_env_list(void);

t_node_env *_env_get_node(t_node_env **list, char *key)
{
	while (list && *list)
	{
		if (_string().equals((*list)->key, key))
		{
			return (*list);
		}
		list = &(*list)->next;
	}
	return (NULL);
}

t_node_env *_env_get(char *key)
{
	return (_env_get_node(_env_list(), key));
}
