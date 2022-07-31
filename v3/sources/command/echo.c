#include "../../includes/command.h"

char *_command_pre_echo(t_node_command *invoker, t_node_command *this)
{
	printf("command pre %s\n", this->name);
	if (this->next)
		this->next->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void _command_echo(t_node_command *this)
{
	if (this->next)
		printf("%s\n", this->next->pre_function(this, this->next));
	_command().delete(this);
}
