#include "../../includes/command.h"

t_command _command(void)
{
	static t_command _command = {
		_command_list,
		_command_create,
		_command_execute,
		_command_delete,
		_command_delete_all};

	return (_command);
}

t_node_command **_command_list(void)
{
	static t_node_command *command;

	return (&command);
}
