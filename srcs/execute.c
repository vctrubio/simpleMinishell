#include "../include/minishell.h"

void	ft_execute_single_tkn(t_tkn *tkn)
{
	ft_pipe(tkn->cmd, tkn->args);
}

void	ft_exec(t_tkn *tkn)
{
	t_tkn	*ptr;
	ptr = tkn;
	print_tkn(ptr);
	t_tkn	*next;
	int		i;

	while (tkn)
	{
		next = tkn->next;
		// ft_execute_single_tkn(tkn);
		tkn = tkn->next;
	}

	// printf("\n");
}