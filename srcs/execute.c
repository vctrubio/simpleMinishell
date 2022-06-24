#include "../include/minishell.h"

int		scan_array(char *str) // 0 if nothing to do, 1 if quotes, 2 if $
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
			i = 1;
		if (*str == '$' && i != 1)
			i = 2;
		str++;
	}
	return (i);
}

void		dollar_for_money(char **out, char **str)
{
	char	*tmp;
	int		i;
	int		j;

	i = ft_strlen(*out);
	j = 0;
	(*str)++;
	if (**str == '?')
	{
		(*str)++;
		tmp = ft_itoa(get_shell()->ec);
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
	else
	{
		while ((*str)[j] != '$' && !ft_isspace((*str)[j]) && !ft_isquote((*str)[j]) && (*str)[j])
			j++;
		tmp = ft_strldup(*str, j);
		(*str) += j;
		tmp = parse_var_env(tmp);
		j = 0;
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
	// printf("OUT1 is %s\n", *out);
}


char	*parse_array(char *str)
{
	char	*out;
	int 	i;

	out = malloc(sizeof(char) * 400); //we dunno what the potential size can be
	i = 0;
	while (*str)
	{
		i = ft_strlen(out);
		if (*str == '"') //do single quote function
			continue;
		else if (*str == '"') //do db quote function
			continue;
		else if (*str == '$') //dollar for money function
			dollar_for_money(&out, &str);
		else
		{
			out[i] = *str;
			str++;
		}
	}
	// printf("OUT is %s\n", out);
	return (out);
}


//simple ls command
void	ft_exec(char **array)
{
	char	*ptr;

	while (*array)
	{
		ptr = parse_array(*array);
		printf("%s ", ptr);
		(array)++;
	}
		printf("\n");

}