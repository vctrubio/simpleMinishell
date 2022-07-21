/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:28:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 05:06:15 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_cd(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_cd(t_command *command)
{
	printf("command %s\n", command->name);
	_command_free(command);
}

char	*command_pre_env(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_env(t_command *command)
{
	printf("command %s\n", command->name);
}

char	*command_pre_pwd(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_pwd(t_command *command)
{
	printf("command %s\n", command->name);
}

char	*command_pre_echo(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_echo(t_command *command)
{
	if (command->next)
		printf("%s\n", (command->next->pre_function)(command->next));
	_command_free(command);
}

char	*command_pre_exit(t_command *command)
{
	char	*name;

	name = command->name;
	_command_free(command);
	return (name);
}

void	command_exit(t_command *command)
{
	printf("command %s\n", command->name);
	exit(0);
}
