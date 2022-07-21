/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:18:59 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/06 00:33:46 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

# include "string.h"
# include "prompt.h"
# include "env.h"
# include "parse.h"

typedef struct s_command	t_command;
typedef void				(*t_function)(t_command *command);
typedef char				*(*t_pre_function)(t_command *command);

struct	s_command
{
	int				error;
	int				cmd;
	int				fd[2];
	char			*name; // ls 
	t_pre_function	pre_function;
	t_function		function;
	t_command		*prev;
	t_command		*next;
};

int				_names(char	*name);
t_function		_functions(int index);
t_pre_function	_pre_functions(int index);

char			*command_pre_cd(t_command *command);
char			*command_pre_env(t_command *command);
char			*command_pre_pwd(t_command *command);
char			*command_pre_echo(t_command *command);
char			*command_pre_exit(t_command *command);
char			*command_pre_unset(t_command *command);
char			*command_pre_system(t_command *command);
char			*command_pre_export(t_command *command);
char			*command_pre_redirect(t_command *command);

void			command_cd(t_command *command);
void			command_env(t_command *command);
void			command_pwd(t_command *command);
void			command_echo(t_command *command);
void			command_exit(t_command *command);
void			command_unset(t_command *command);
void			command_system(t_command *command);
void			command_export(t_command *command);
void			command_redirect(t_command *command);

int				size_of_command(void);
void			execute_command(void);
int				_command_free(t_command *command);
void			init_command(char *cmds, t_pre_function pre_function, \
t_function function);

#endif
