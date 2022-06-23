
#include "../include/minishell.h"

void	ft_dquote(char **str, char flag)
{
	int		i;
	char	*buff;
	bool	even_quotation;

	i = ft_strlen(*str);
	even_quotation = false;
	buff = readline("dquote>");
	add_history(buff); //with a new line if possible
	while (*buff)
	{
		if (*buff == flag)
		{
			even_quotation = !even_quotation;
			buff++;
		}
		if (*buff)
			(*str)[i++] = *buff;
		buff++;
	}
	if (even_quotation == false)
		ft_dquote(str, flag);
}