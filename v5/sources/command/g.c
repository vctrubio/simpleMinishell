#include "../../includes/command.h"

char *_command_pre_g(t_node_command *invoker, t_node_command *this)
{
	char *name;

	name = NULL;
	if (this->next)
		name = this->next->pre_function(invoker, this->next);
	(void)name;
	_command().delete(this);
	return (invoker->name);
}

void _command_g(t_node_command *this)
{
	char *name;
	t_node_env *env;

	name = NULL;
	if (this->next)
		name = this->next->pre_function(this, this->next);
	env = _env().get(name);
	printf("*%s*\n", env->value);
	_command().delete(this);
}
