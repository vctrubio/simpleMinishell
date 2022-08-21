/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:06 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 18:59:35 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char *_command_pre_echo(t_node_command *invoker, t_node_command *this)
{
	printf("command pre %s\n", this->name);
	if (this->next)
		this->next->builting->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void _command_echo(t_node_command *this)
{
	char	*name;

	name = "\n";
	if (this->next)
	{
		name = this->next->builting->pre_function(this, this->next);
		if (_string().beginning_equals(name, "-n"))
			write(1, name + 3, _string().length(name + 3));
		else
			write(1, name, _string().length(name));
	}
	if (!_string().beginning_equals(name, "-n"))
		write(1, "\n", 1);
	_command().delete(this);
}
