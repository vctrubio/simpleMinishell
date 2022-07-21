/*


// void	parse_string(char **str, t_array *a, char flag);
// void	parse_buffer_loop(char **str, t_array *array);
// t_array	*parse_buffer(char *str);

int		ft_scan_content(char *str)
{
	int count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '"' || str[i] == '\'')
			count++;
	}
	return (count);
}

		if ()
		{
			printf("YES\n");
			break;
		}
		// tkn->args[j] = malloc(sizeof(char) * ft_strlen(a[*index]));
		tkn->args[j++] = ft_strdup(a[*index]);


t_array	*buff_to_tarray(char **array)
{
	t_array	*tmp;
	t_array	*prev;
	int		i;

	tmp = NULL;
	prev = NULL;
	while (array[i])
	{
		tmp = malloc(sizeof(t_array));
		tmp->cmd = ft_strdup(array[i++]);
		if (prev)
			prev->next = tmp;
		tmp->prev = prev;
		prev = tmp;
	}
	while (tmp->prev)
		tmp = tmp->prev;
	print_tarrays(tmp);
	return (tmp);
}


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



void	array_into_tokens(char **a) // return false if error
{
	//HERE
	//goal, try and ge heredoc input
	int		i;
	char	*ptr;

	i = 0;
	while(a[i])
	{
		ptr = parse_array(a[i]);
		i++;
	}

}












*/