#include "../../includes/command.h"

void _command_add(t_node_command *node)
{
	t_node_command **list;

	list = _command_list();
	if (!*list)
		*list = node;
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = node;
		node->prev = *list;
	}
}
