/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:45:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 18:58:40 by joaribei         ###   ########.fr       */
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
# include <sys/types.h>

# include "minishell.h"
# include "string.h"
# include "memory.h"
# include "file.h"
# include "env.h"

typedef struct s_command		t_command;
typedef struct s_builting		t_builting;
typedef struct s_node_builting	t_node_builting;
typedef struct s_node_command	t_node_command;

typedef void					(*t_function)(t_node_command *this);
typedef char					*(*t_pre_function)(t_node_command *invoker,
									t_node_command *this);
struct s_node_builting
{
	char			*name;
	t_node_builting	*prev;
	t_node_builting	*next;
	t_pre_function	pre_function;
	t_function		function;
};

struct s_node_command
{
	int				error;
	int				cmd;
	int				fd[2];
	char			*name;
	t_node_command	*next;
	t_node_command	*prev;
	t_node_builting	*builting;
};

struct s_builting
{
	t_node_builting	**(*list)(void);
	void			(*create)(char *name);
	void			(*execute)(void);
	void			(*delete)(t_node_builting *command);
	void			(*delete_all)(void);
};

struct s_command
{
	t_node_command	**(*list)(void);
	void			(*create)(char *name);
	void			(*execute)(void);
	void			(*delete)(t_node_command *command);
	void			(*delete_all)(void);
};

char			*_command_token(char **name, t_node_command *command);

t_command		_command(void);
t_node_command	**_command_list(void);

t_node_builting	*_builting(char *name);
t_node_builting	**_builting_list(void);

void			_command_execute(void);
void			_command_create(char *name);
void			_command_add(t_node_command *node);
void			_command_delete(t_node_command *command);
void			_command_delete_all(void);

void			_builting_create(char *name, t_pre_function pre_function,
					t_function function);
void			_builting_add(t_node_builting *node);
void			_builting_delete(t_node_builting *command);
void			_builting_delete_all(void);

char			*_command_pre_cd(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_env(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_echo(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_unset(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_system(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_export(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_greater_than(t_node_command *invoker,
					t_node_command *this);
char			*_command_pre_more_greater_than(t_node_command *invoker,
					t_node_command *this);

void			_command_cd(t_node_command *this);
void			_command_env(t_node_command *this);
void			_command_echo(t_node_command *this);
void			_command_unset(t_node_command *this);
void			_command_system(t_node_command *this);
void			_command_export(t_node_command *this);
void			_command_greater_than(t_node_command *this);
void			_command_more_greater_than(t_node_command *this);

#endif
