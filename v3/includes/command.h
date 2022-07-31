#ifndef COMMAND_H
#define COMMAND_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>

#include "string.h"
#include "memory.h"
#include "file.h"
#include "env.h"

typedef struct s_node_command t_node_command;
typedef struct s_command t_command;
typedef void (*t_function)(t_node_command *this);
typedef char *(*t_pre_function)(t_node_command *invoker, t_node_command *this);

struct s_node_command
{
	t_node_command *prev;
	t_node_command *next;
	int error;
	int cmd;
	int fd[2];
	char *name;
	t_pre_function pre_function;
	t_function function;
};

struct s_command
{
	t_node_command **(*list)(void);
	void (*create)(char *name);
	void (*execute)(void);
	void (*delete)(t_node_command *command);
	void (*delete_all)(void);
};

t_command _command(void);

t_node_command **_command_list(void);
void _command_create(char *name);
void _command_execute(void);
void _command_delete(t_node_command *command);
void _command_delete_all(void);

char *_command_pre_echo(t_node_command *invoker, t_node_command *this);
char *_command_pre_cd(t_node_command *invoker, t_node_command *this);
char *_command_pre_greater_than(t_node_command *invoker, t_node_command *this);
char *_command_pre_more_greater_than(t_node_command *invoker, t_node_command *this);
char *_command_pre_system(t_node_command *invoker, t_node_command *this);

void _command_echo(t_node_command *this);
void _command_cd(t_node_command *this);
void _command_greater_than(t_node_command *this);
void _command_more_greater_than(t_node_command *this);
void _command_system(t_node_command *this);
#endif
