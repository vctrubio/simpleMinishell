#include "../include/minishell.h"

void	parse_string(char **str, t_array *a, char flag)
{
	int		i;
	bool	even_quote;

	even_quote = false;
	i = 0;
	a->content = malloc(sizeof(char) * ft_strlen(*str) + 1);
	if (!flag)
	{
		while (**str && !ft_isspace(**str))
			a->content[i++] = *(*str)++;
	}
	else if (flag)
	{
		(*str)++;
		while (**str)
		{
			if (**str == flag)
				even_quote = !even_quote;
			else
				a->content[i++] = **str;
			(*str)++;
		}
		if (!even_quote)
			ft_dquote(&a->content, flag);
	}
}

void	parse_buffer_loop(char **str, t_array *array)
{
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str == 0)
		return ;
	if (**str == '\'')
		parse_string(&(*str), array, **str);
	else if (**str == '"')
		parse_string(&(*str), array, **str);
	else
		parse_string(&(*str), array, (char)NULL);
}

t_array	*parse_buffer(char *str)
{
	t_array	*head;
	t_array	*next;
	t_array	*prev;

	head = rtn_t_array();
	parse_buffer_loop(&str, head);

	prev = NULL;
	while (*str)
	{
		next = rtn_t_array();
		parse_buffer_loop(&str, next);
		if (prev)
			prev->next = next;
		if (head->next == NULL)
			head->next = next;
		prev = next;
	}
	return(head);
}

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

void	init_parse(char *buffer)
{
	t_array	*ptr;
	t_array	*ptr2;

	ptr = parse_buffer(buffer);
	// ft_store_tarry(ptr);
	print_tarrays(ptr);
	free_tarrays(&ptr);


	// ptr2 = ft_store_tarry((t_array *)NULL);

	// while (ptr)
	// {
	// 	if (ptr)
	// 		parse_content(ptr);
	// 	ptr = ptr->next;
	// }

}
