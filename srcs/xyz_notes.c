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