/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:20:16 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/06 00:34:27 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_command	**_command(int option)
{
	static t_command	*first;
	static t_command	*last;

	if (option)
		return (&last);
	return (&first);
}

int	size_of_command(void)
{
	int	i;

	i = 0;
	printf("size_of_command ");
	(*_command(1)) = (*_command(0));
	while ((*_command(1)))
	{
		i++;
		(*_command(1)) = (*_command(1))->next;
	}
	return (i);
}

void	_command_add(t_command **new_command)
{
	if (!(*_command(0)))
		(*_command(0)) = (*new_command);
	else
	{
		(*_command(1)) = (*_command(0));
		while ((*_command(1))->next)
			(*_command(1)) = (*_command(1))->next;
		(*new_command)->prev = (*_command(1));
		(*_command(1))->next = (*new_command);
	}
	(*_command(1)) = (*new_command);
}

int	_command_free(t_command *command)
{
	if (command)
	{
		(*_command(1)) = (*_command(0));
		while ((*_command(1)))
		{
			if ((*_command(1)) == command)
				break ;
			(*_command(1)) = (*_command(1))->next;
		}
		if (!(*_command(1)))
			return (1);
		if ((*_command(1))->prev && (*_command(1))->next)
		{
			(*_command(1))->prev->next = (*_command(1))->next;
			(*_command(1))->next->prev = (*_command(1))->prev;
		}
		else if (!(*_command(1))->prev)
		{
			(*_command(0)) = (*_command(0))->next;
			if ((*_command(0)))
				(*_command(0))->prev = NULL;
		}
		else if (!(*_command(1))->next)
			(*_command(1))->prev->next = NULL;
		_memory().free((*_command(1)));
		(*_command(1)) = (*_command(0));
	}
	return (0);
}

void	init_command(char *cmds, t_pre_function pre_function, t_function function)
{
	t_command	*command;

	command = (t_command *)_memory().malloc(sizeof(t_command));
	command->error = 0;
	command->name = parse_array(cmds);
	command->pre_function = pre_function;
	command->function = function;
	command->next = NULL;
	command->prev = NULL;
	_command_add(&command);
}

void	execute_command(void)
{
	while ((*_command(0)))
	{
		(*_command(1)) = (*_command(0));
		(*(*_command(1))->function)((*_command(1)));
	}
}
