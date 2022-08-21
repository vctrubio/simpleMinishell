/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:12 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 19:09:37 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

void	_builting_create(char *name, t_pre_function pre_function,
	t_function function)
{
	t_node_builting	*builting;

	builting = _memory().calloc(1, sizeof(t_node_builting));
	builting->name = name;
	builting->pre_function = pre_function;
	builting->function = function;
	_builting_add(builting);
}

void	_command_create(char *name)
{
	t_node_command	*command;

	command = _memory().calloc(1, sizeof(t_node_command));
	command->fd[0] = 0;
	command->builting = _builting(name);
	command->name = name;
	_command_add(command);
}
