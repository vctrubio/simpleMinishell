#include "../../includes/command.h"

int				_command_name(char *name);
void			_command_add(t_node_command *node);
t_function		_command_function(int index);
t_pre_function	_command_pre_function(int index);

void _command_create(char *name)
{
	int				index_name;
	t_node_command *command;

	command = _memory().malloc(sizeof(t_node_command));
	command->prev = NULL;
	command->next = NULL;
	command->name = _string().dup(name);
	command->fd[0] = 0;
	index_name = _command_name(name);
	command->pre_function = _command_pre_function(index_name);
	command->function = _command_function(index_name);
	_command_add(command);
}
