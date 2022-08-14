#include "../../includes/command.h"

int _command_name(char *name)
{
	unsigned long index;
	static char _names[6][14] = {
		"echo",
		"cd",
		">",
		">>",
		"export",
		"g"};
	index = -1;
	while (++index < (sizeof(_names) / sizeof(*_names)))
		if (_string().equals(name, _names[index]) > 0)
			return (index);
	return (index);
}