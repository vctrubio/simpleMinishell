#include "../../includes/env.h"

void _env_add(t_node_env *malloc);

void *_env_create(char *string)
{
	t_node_env *new_node;
	char		**split;

	new_node = _memory().malloc(sizeof(t_node_env));
	split = _string().split_char(string, '=');
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->key = split[0];
	new_node->value = split[1];
	new_node->value_size = _string().length(split[1]);
	_env_add(new_node);
	_memory().free(split);
	return (new_node);
}
