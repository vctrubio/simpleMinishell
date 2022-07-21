#include "../includes/minishell.h"

char		*parse_var_env(char *str) //returns $PWD into (User/v/Home)
{
	return (get_env(str)->value);
}


void	dollar_for_money(char **out, char **str)
{
	char	*tmp;
	int		i;
	int		j;

	i = _string().length(*out);
	j = 0;
	(*str)++;
	tmp = NULL;
	if (**str == '?')
	{
		(*str)++;
		tmp = _string().itoa(get_shell()->ec); 
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
	else
	{
		while ((*str)[j] != '$' && !_char().is_whitespace((*str)[j]) && !_string().isquote((*str)[j]) && (*str)[j])
			j++;
		tmp = _string_dup_at(*str, j);
		(*str) += j;
		tmp = parse_var_env(tmp);
		j = 0;
		while (tmp[j])
			(*out)[i++] = tmp[j++];
	}
}

void	ft_squote(char **out, char **str)
{
	int	i;

	i = _string().length(*out);
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
		i = _string().length(*out);
		if (**str == '$' && (**str + 1 != '\'' || **str + 1 != '"'))
			dollar_for_money(out, str);
		else
			(*out)[i] = *(*str)++;
	}
}

char	*parse_array(char *str)
{
	int		i;
	char	*out;

	out = _memory().malloc(sizeof(char) * 400);
	i = 0;
	while (*str)
	{
		i = _string().length(out);
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
	out[_string().length(out) + 1] = 0;
	return (out);
}


/* to watch out for
* echo / $PWD'out' / $PWD$USR / $PWDout / $'this'
* echo "$PWD" / '$PWD' / "$'PWD'"

*/
