#include "../../includes/command.h"

void _command_delete(t_node_command *command)
{
	t_node_command **list;

	list = _command_list();
	if (*list == command)
		*list = command->next;
	if (command->next)
		command->next->prev = command->prev;
	if (command->prev)
		command->prev->next = command->next;
	if (*list)
	{
		_memory().free(command);
		_memory().free(command);
	}
}

void _command_delete_all(void)
{
	t_node_command **list;

	list = _command_list();
	while (*list)
		_command_delete(*list);
}
