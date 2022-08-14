#include "../../includes/command.h"

t_function _command_function(int index)
{
	static t_function functions[7] = {
		_command_echo,
		_command_cd,
		_command_greater_than,
		_command_more_greater_than,
		_command_export,
		_command_g,
		_command_system};

	if (index < 0)
		return (0);
	return (functions[index]);
}
