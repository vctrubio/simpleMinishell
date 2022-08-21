/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:17 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 19:04:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*_command_pre_unset(t_node_command *invoker, t_node_command *this)
{
	if (this->next)
		this->next->builting->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void	_command_unset(t_node_command *this)
{
	char	*name;

	name = NULL;
	if (this->next)
	{
		name = this->next->builting->pre_function(this, this->next);
		if (name)
			_env().delete(name);
	}
	_command().delete(this);
}
