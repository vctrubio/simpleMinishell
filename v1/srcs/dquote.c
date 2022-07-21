#include "../include/minishell.h"

void	ft_dquote(char **output, char c)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = 1; //flag: we have already 1 ", we need an even number of "
	buff = readline("dquote> ");
	add_history(buff);
	tmp = ft_strdup(buff);
	ft_stradd(&(*output), tmp);
	i += ft_strcount_char(tmp, c);
	if (i % 2 != 0)
		ft_dquote(output, c);
}
