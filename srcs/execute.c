#include "../include/minishell.h"

void	ft_execute_single_tkn(t_tkn *tkn)
{
	ft_pipe(tkn->cmd, tkn->args);
}

void	ft_exec(void)
{
	t_tkn	*ptr;
	t_tkn	*next;
	int		i;

	i = 0;
	ptr = get_shell()->tkn;
	print_tkn(ptr);
	printf("%d #of tokens\n", get_shell()->count_tkn);

	// printf("\n");
}

/* HERE atm
if 1 token, 1 command
if 2 tokens, pipe or rdirect




*/