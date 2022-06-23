#include "../include/minishell.h"

void	ft_dquote(char **output, char c)
{
	char	*buff;
	bool	even_quotation;
	int		i;

	i = ft_strlen(*output);
	even_quotation = false; //flag: we have already 1 ", we need an even number of "
	buff = readline("dquote> ");
	add_history(buff);
	while (*buff)
	{
		if (*buff == c)
			even_quotation = !even_quotation;
		(*output)[i++] = *buff;
		buff++;
	}
	if (even_quotation == false)
		ft_dquote(output, c);
	//slight errror when there is a bit too many.... to check it out
}
