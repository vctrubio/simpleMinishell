/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:42 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 19:01:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char *_command_pre_pipe(t_node_command *invoker, t_node_command *this)
{
	char	*name;

	name = NULL;
	if (this->next)
		name = this->next->builting->pre_function(invoker, this->next);
	(void)name;
	_command().delete(this);
	return (invoker->name);
}

void _command_pipe(t_node_command *this)
{
	char		*name;
	t_node_env	*env;

	name = NULL;
	if (this->next)
		name = this->next->builting->pre_function(this, this->next);
	env = _env().get(name);
	printf("*%s*\n", env->value);
	_command().delete(this);
}
