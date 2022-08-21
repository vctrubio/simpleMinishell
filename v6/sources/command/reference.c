/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:28 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 21:43:02 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_command	_command(void)
{
	static t_command	_command = {
		_command_list,
		_command_create,
		_command_execute,
		_command_delete,
		_command_delete_all};

	return (_command);
}

t_node_builting	*_builting(char *name)
{
	t_node_builting	**builtings;

	builtings = _builting_list();
	if (!*builtings)
	{
		_builting_create("echo", _command_pre_echo, _command_echo);
		_builting_create("cd", _command_pre_cd, _command_cd);
		_builting_create(">", _command_pre_greater_than, _command_greater_than);
		_builting_create(">>", _command_pre_more_greater_than, _command_more_greater_than);
		_builting_create("export", _command_pre_export, _command_export);
		_builting_create("unset", _command_pre_unset, _command_unset);
		_builting_create("env", _command_pre_env, _command_env);
		_builting_create("system", _command_pre_system, _command_system);
	}
	while ((*builtings)->next)
	{
		if (_string().equals((*builtings)->name, name))
			return (*builtings);
		builtings = &(*builtings)->next;
	}
	return (*builtings);
}

t_node_builting	**_builting_list(void)
{
	static t_node_builting	*builting;

	return (&builting);
}

t_node_command	**_command_list(void)
{
	static t_node_command	*command;

	return (&command);
}
