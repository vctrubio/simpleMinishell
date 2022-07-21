/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:14:26 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/06 20:24:30 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

char	*command_pre_system(t_command *command)
{
	char	*name;

	if (command->next)
	{
		name = ft_strjoin(command->name, " ");
		name = ft_strjoin(name, command->next->pre_function(command->next));
	}
	else
		name = ft_strjoin(command->name, "");
	_command_free(command);
	return (name);
}


char	*get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*inter;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmd);
		_memory().free(inter);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		_memory().free(cmd_path);
		i++;
	}
	return (NULL);
}

void	terminate(char *m)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(m);
	exit(EXIT_FAILURE);
}

void	command_system(t_command *command)
{
	char	*name;
	char	**args;
	char	**paths;
	char	*path;
	int		test;
	pid_t	c_pid;

	test = 0;
	if (command->next)
	{
		name = ft_strjoin(command->name, " ");
		name = ft_strjoin(name, command->next->pre_function(command->next));
	}
	else
		name = ft_strjoin(command->name, "");
	if (!command->error)
	{
		c_pid = fork();
		if (c_pid < 0)
			terminate("fork");
		if (c_pid == 0)
		{
			args = _string().split_char(name, ' ');
			path = get_env("PATH")->value;
			paths = _string().split_char(path, ':');
			while (args[test])
				test++;
			args[test] = NULL;
			execve(get_cmd(paths, command->name), args, NULL);
		}
		wait(NULL);
	}
	_command_free(command);
}
