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
		
		tkn = tkn->next;
	}

	printf("\n");
}