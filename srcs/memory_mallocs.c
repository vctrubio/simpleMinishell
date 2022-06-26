#include "../include/minishell.h"
t_tkn	*rtn_token(char *cmd);

t_tkn	*rtn_token(char *cmd)
{
	t_tkn	*t;

	t = malloc(sizeof(t_tkn));
	t->cmd = ft_strdup(cmd);
	t->next = NULL;
	t->cmd_path = NULL;
	t->args = malloc(800); // the size can be infinite
	// printf("rtn_token:CMD %s\n", t->cmd);
	return (t);
}

