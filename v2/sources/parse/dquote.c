#include "../includes/parse.h"

void	ft_dquote(char **output, char c)
{
	char	*buff;
	char	*tmp;
	int		i;

	i = 1;
	buff = readline("dquote> ");
	add_history(buff);
	tmp = _string().dup(buff);
	_stradd(&(*output), tmp);
	i += _strcount_char(tmp, c);
	if (i % 2 != 0)
		ft_dquote(output, c);
}
