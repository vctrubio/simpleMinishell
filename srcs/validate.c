#include "../include/minishell.h"

void	ft_validate(void)
{
	t_shell	*shell;
	t_tkn	*tkn_ptr;
	int		count;

	shell = get_shell();
	tkn_ptr = shell->tkn;
	count = 0;
	while (tkn_ptr)
	{
		count++;
		tkn_ptr = tkn_ptr->next;
	}
	shell->count_tkn = count;
}