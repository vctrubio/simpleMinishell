/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 08:24:31 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

void	_command_delete(t_node_command *command)
{
	t_node_command	**list;

	list = _command_list();
	if (*list == command)
		*list = command->next;
	if (command->next)
		command->next->prev = command->prev;
	if (command->prev)
		command->prev->next = command->next;
	if (*list)
		_memory().free(command);
}

void	_builting_delete(t_node_builting *builting)
{
	t_node_builting	**list;

	list = _builting_list();
	if (*list == builting)
		*list = builting->next;
	if (builting->next)
		builting->next->prev = builting->prev;
	if (builting->prev)
		builting->prev->next = builting->next;
	if (*list)
		_memory().free(builting);
}

void	_command_delete_all(void)
{
	t_node_command	**list;

	list = _command_list();
	while (*list)
		_command_delete(*list);
}

void	_builting_delete_all(void)
{
	t_node_builting	**list;

	list = _builting_list();
	while (*list)
		_builting_delete(*list);
}
