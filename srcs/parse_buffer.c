#include "../include/minishell.h"

char	*buffer_quotes(char **buff, char c, char *str, int i);
char	*buffer_scan_for_quotes(char *str);
char	*buffer_to_string(char **buff);
char	**buffer_into_array(char *str);

char	*buffer_quotes(char **buff, char c, char *str, int i)
{
	str[(i)++] = *(*buff)++;
	while (**buff && **buff != c)
		str[(i)++] = *(*buff)++;
	if (**buff == c)
		str[(i)++] = *(*buff)++;
	return (str);
}

char	*buffer_scan_for_quotes(char *str)
{
	char	*output;
	int		i; 
	int		f; //first occurance for finding c
	char	c; //c if ' or "
	char	k; //count c

	f = 0;
	k = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == '\'' || str[i] == '"'))
		{
			if (f++ == 0)
				c = str[i];
		}
		if (str[i] == c)
			k++;
	}
	if (k % 2 != 0)
		ft_dquote(&str, c);
	return (str);
}

char	*buffer_to_string(char **buff)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * ft_strlen(*buff) + 1);
	i = 0;
	while (**buff)
	{
		i = ft_strlen(str);
		if (ft_isspace(**buff))
			break;
		if ((**buff == '<' || **buff == '>' || **buff == '|'))
		{
			if (i != 0)
				return (str);
			str[i++] = *(*buff)++;
			if (**buff == str[i - 1])
				str[i++] = *(*buff)++;
			return (str);
		}
		if ((**buff == '\'' || **buff == '"') && *(*buff + 1) == **buff)
		{
			(*buff)++; (*buff)++;
		}
		if ((**buff == '\'' || **buff == '"') && (**buff + 1 != **buff))
			str = buffer_quotes(&(*buff), **buff, str, i);
		else if (**buff)
			str[i++] = *(*buff)++;
	}
	return (buffer_scan_for_quotes(str));
}

char	**buffer_into_array(char *str)
{
	char	**a;
	int		l;
	int		i;

	i = 0;
	l = r_size(str);
	a = malloc(sizeof(char) * l + 1);
	while (*str)
	{
		// printf("EVAULTE %s\n", str);
		while (ft_isspace(*str))
			str++;
		if (!str)
			break;
		a[i++] = ft_strdup(buffer_to_string(&str)); //printf("a copied %s\n", a[i - 1]);
	}
	a[i] = 0;
	return(a);
}
