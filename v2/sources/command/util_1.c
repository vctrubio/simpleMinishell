/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 08:19:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 23:06:15 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

int	_names(char	*name)
{
	unsigned long	index;
	static char		_names[8][10] = {
		"cd",
		"env",
		"pwd",
		"echo",
		"exit",
		"unset",
		"export",
		">"
	};

	index = 0;
	while (index < (sizeof(_names) / sizeof(*_names)))
	{
		if (_string().equals(name, _names[index]) > 0)
			return (index);
		index++;
	}
	return (-1);
}

t_pre_function	_pre_functions(int index)
{
	static t_pre_function	functions[8] = {
		command_pre_cd,
		command_pre_env,
		command_pre_pwd,
		command_pre_echo,
		command_pre_exit,
		command_pre_unset,
		command_pre_export,
		command_pre_redirect
	};

	if (index < 0)
		return (command_pre_system);
	return (functions[index]);
}

t_function	_functions(int index)
{
	static t_function	functions[8] = {
		command_cd,
		command_env,
		command_pwd,
		command_echo,
		command_exit,
		command_unset,
		command_export,
		command_redirect
	};

	if (index < 0)
		return (command_system);
	return (functions[index]);
}
