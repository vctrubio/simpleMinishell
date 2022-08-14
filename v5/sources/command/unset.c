#include "../../includes/command.h"

char *_command_pre_unset(t_node_command *invoker, t_node_command *this)
{
	if (this->next)
		this->next->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void _command_unset(t_node_command *this)
{
	t_node_env *env;
	char *name;
	char **string;

	env = NULL;
	name = NULL;
	if (this->next)
	{
		name = this->next->pre_function(this, this->next);
		if (name)
		{
			string = _string().split_char(name, ' ');
			env = _env().get(string[0]);
		}
		if (env)
		{
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
			_memory().free(env->value);
			env->value = string[1];
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
		}
		else
		{
			_env().create(name);
			printf("declare -y %s=\"%s\"\n", env->key, env->value);
		}
	}
	else
	{
		env = *_env().list();
		while (env)
		{
			printf("declare -x %s=\"%s\"\n", env->key, env->value);
			env = env->next;
		}
	}

	_command().delete(this);
}
