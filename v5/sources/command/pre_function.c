#include "../../includes/command.h"

t_pre_function _command_pre_function(int index)
{
	static t_pre_function functions[7] = {
		_command_pre_echo,
		_command_pre_cd,
		_command_pre_greater_than,
		_command_pre_more_greater_than,
		_command_pre_export,
		_command_pre_g,
		_command_pre_system};

	if (index < 0)
		return (0);
	return (functions[index]);
}
