#include "../include/minishell.h"


static int		r_size(char *s)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			++s;
		else
		{
			++len;
			while (*s && !ft_isspace(*s))
				++s;
		}
	}
	return (len);
}

char	*buffer_quotes(char **buff, char c, char *str, int i)
{
	printf("BINGO\n");
	str[(i)++] = *(*buff)++;
	while (**buff && **buff != c)
	{
		str[(i)++] = **buff;
		// printf("cp%c ", str[(*i)]);
		(*buff)++;
	}
	if (**buff == c)
		str[(i)++] = *(*buff)++;
	return (str);
}

char	*buffer_scan_for_quotes(char *str)
{
	char	*output;
	int		i;
	int		f;
	char	c;
	char	k;

	f = 0;
	k = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == '\'' || str[i] == '"') && f == 0)
			c = str[i];
		if (str[i] == c)
			k++;
		i++;
	}
	if (k % 2 != 0)
	{
		printf("not even quotes");
	}
	return (str);
}


char	*buffer_to_string(char **buff)
{
	char	*str;
	int		i;
	bool	q; //quote
	int		f;
	char	c;

	q = false;
	str = malloc(sizeof(char) * ft_strlen(*buff) + 1);
	i = 0;
	f = 0;
	while (**buff)
	{
		i = ft_strlen(str);
		if (ft_isspace(**buff))
			break;
		if ((**buff == '\'' || **buff == '"') && (**buff + 1 != **buff))
			str = buffer_quotes(&(*buff), **buff, str, i);
		else
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
		while (ft_isspace(*str))
			str++;
		if (!str)
			break;
		a[i++] = buffer_to_string(&str);
		printf("a copied %s\n", a[i - 1]);
		str++;
	}

	printf("we have %d arrays\n", l);
	return(a);
}



int main()
{
	printf("main\n");
	char 	*buff;
	char	**buff_array;
	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		buff_array = buffer_into_array(buff);
		//array_into_tokens
		//validate
		free_str(buff);
		// free_arrays(buff_array);
	}
}