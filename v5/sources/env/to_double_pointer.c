#include "../../includes/env.h"

char **_env_to_double_pointer(void)
{
	size_t index;
	size_t key_size;
	size_t value_size;
	t_node_env *env;
	char **double_pointer;

	index = 0;
	env = *_env().list();
	if (env)
		double_pointer = _memory().calloc(sizeof(char *), (_env().size() + 1));
	while (env)
	{
		key_size = _string().length(env->key);
		value_size = _string().length(env->value);
		double_pointer[index] = _memory().calloc(sizeof(char), (key_size + value_size + 2));
		_string().copy(double_pointer[index], env->key);
		_string().copy(double_pointer[index] + key_size, "=");
		_string().copy(double_pointer[index] + key_size + 1, env->value);
		++index;
		env = env->next;
	}
	return (double_pointer);
}
