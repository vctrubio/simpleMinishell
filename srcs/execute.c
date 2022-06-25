#include "../include/minishell.h"

void	exec_ptr(char *str)
{
	char	**env;

	env = get_shell()->envp;
	/*
	-path 
	-cmd
	-args
	-direction
	-pipe
	*/
	printf("exec_ptr: %s \n", str);
}


//simple ls command
void	ft_exec(t_tkn *tkn)
{
	char	*ptr;
	int		i;

	i = 0;
	while (tkn)
	{
		// if (ft_enum_token(tkn->cmd) == IS_CMD)
			ft_pipe(tkn->cmd, tkn->args);
		// ptr = parse_array(*array);
		tkn = tkn->next;
	}

	printf("\n");
}