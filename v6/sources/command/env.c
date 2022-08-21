/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:03 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 19:00:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*_command_pre_env(t_node_command *invoker, t_node_command *this)
{
	char	*name;

	name = NULL;
	if (this->next)
		name = this->next->builting->pre_function(invoker, this->next);
	(void)name;
	_command().delete(this);
	return (invoker->name);
}

void	_command_env(t_node_command *this)
{
	t_node_env	*env;

	env = *_env().list();
	while (env)
	{
		if (env->signal)
		{
			if (env->value)
				printf("%s=%s\n", env->key, env->value);
			else
				printf("%s=\n", env->key);
		}
		env = env->next;
	}
	_command().delete(this);
}
