#include "../include/minishell.h"
void	dollar_for_money(char **out, char **str);
char	*parse_array(char *str);
void	ft_squote(char **out, char **str);
void	ft_db_quote(char **out, char **str);

void	dollar_for_money(char **out, char **str)
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

void	ft_squote(char **out, char **str)
{
	int	i;

	i = ft_strlen(*out);
	(*str)++;
	while (**str != '\'' && **str)
			(*out)[i++] = *(*str)++;
}

void	ft_db_quote(char **out, char **str)
{
	int	i;

	i = 0;
	(*str)++;
	while (**str != '"' && **str)
	{
		i = ft_strlen(*out);
		if (**str == '$' && (**str + 1 != '\'' || **str + 1 != '"')) //edge case
			dollar_for_money(out, str);
		else
			(*out)[i] = *(*str)++;
	}
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
		if (*str == '\'')
			ft_squote(&out, &str);
		else if (*str == '"')
			ft_db_quote(&out, &str);
		else if (*str == '$')
			dollar_for_money(&out, &str);
		else
		{
			out[i] = *str;
			str++;
		}
	}
	return (out);
}