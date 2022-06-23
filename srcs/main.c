#include "../include/minishell.h"

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
		while (ft_isspace(*str))
			str++;
		if (!str)
			break;
		a[i++] = buffer_to_string(&str); printf("a copied %s\n", a[i - 1]);
		str++;
	}
	a[i] = 0;
	print_arrays(a); //not the same as whileloop
	return(a);
}


int main()
{
	char 	*buff;
	char	**buff_array;
	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		buff_array = buffer_into_array(buff);

		// print_arrays(buff_array);
		//array_into_tokens
		//validate
		free_str(buff);
		// free_arrays(buff_array);
	}
}


/*





*/