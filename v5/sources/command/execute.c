#include "../../includes/command.h"

void _command_execute(void)
{
	while (*_command_list())
		(*_command_list())->function(*_command_list());
}
