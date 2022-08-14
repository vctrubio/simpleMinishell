#include "../../includes/env.h"

size_t _env_size(void)
{
	size_t size;
	t_node_env *env;

	size = 0;
	env = *_env().list();
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}
