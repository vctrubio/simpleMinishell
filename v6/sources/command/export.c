/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:57 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 19:00:30 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*_command_pre_export(t_node_command *invoker, t_node_command *this)
{
	if (this->next)
		this->next->builting->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->builting->name);
}

void	_command_export(t_node_command *this)
{
	t_node_env	*env;
	int			index;
	char		*name;
	char		**string;

	env = NULL;
	name = NULL;
	if (this->next)
	{
		name = this->next->builting->pre_function(this, this->next);
		index = _string().index_of(name, "=");
		if (!index)
			printf("shell: %s: `%s': not a valid identifier\n", this->name, name);
		else
		{
			string = _string().split_char(name, '=');
			env = _env().get(string[0]);
		}
		if (env)
		{
			if (index > 0)
			{
				_memory().free(env->value);
				env->value = string[1];
				env->signal = 1;
			}
		}
		else
			_env().create(name);
		_env().update(&_shell()->env, _env().to_double_pointer());
	}
	else
	{
		env = *_env().list();
		while (env)
		{
			printf("declare -x %s", env->key);
			if (env->signal)
			{
				if (env->value)
					printf("=%s", env->value);
				else
					printf("=\"\"");
			}
			printf("\n");
			env = env->next;
		}
	}
	_command().delete(this);
}
