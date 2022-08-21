/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:23 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 20:25:39 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*_command_token(char **name, t_node_command *command)
{
	unsigned long	index;
	static char		_tokens[8][3] = {
		"||",
		"|",
		"<<",
		"<",
		"&&",
		"&",
		";;",
		";"
	};

	*name = NULL;
	if (!command)
	{
		*name = "newline";
		return ("newline");
	}
	index = -1;
	while (++index < (sizeof(_tokens) / sizeof(*_tokens)))
	{
		if (_string().beginning_equals(command->name, _tokens[index]) > 0)
		{
			*name = _tokens[index];
			return (*name);
		}
	}
	return (NULL);
}
