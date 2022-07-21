/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:31:18 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/06 20:25:48 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_unset(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_unset(t_command *command)
{
	printf("command %s\n", command->name);
}

char	*command_pre_export(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_export(t_command *command)
{
	printf("command %s\n", command->name);
}

char	*command_pre_redirect(t_command *command)
{
	t_command	*tmp;

	if (!command->next)
	{
		printf("Minishell: syntax error near unexpected token `newline'\n");
		tmp = command;
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->error = 1;
		_command_free(command);
	}
	else
	{
		command->fd[0] = open(command->next->pre_function(command->next), O_CREAT | O_WRONLY | O_TRUNC, 0644);
		command->fd[1] = dup(1);
		dup2(command->fd[0], 1);
	}
	// name = command->name;
	return ("");
}

void	command_redirect(t_command *command)
{
	if (command->prev)
	{
		printf("PREV");
		dup2(command->fd[1], 1);
		close(command->fd[0]);
	}
	else if (!command->next)
		printf("Minishell: syntax error near unexpected token `newline'\n");
	else
	{
		command->fd[0] = open(command->next->name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		command->fd[1] = dup(1);
		dup2(command->fd[0], 1);
		if (command->next->next)
			(command->next->next->function)(command->next->next);
		dup2(command->fd[1], 1);
		close(command->fd[0]);
		_command_free(command->next);
	}
	_command_free(command);
}
