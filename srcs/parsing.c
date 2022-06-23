#include "../include/minishell.h"

void	parse_string(char **str, t_array *a, char flag)
{
	int	i;

	i = 0;
	if (!a)
		a = rtn_t_array();
	a->raw = malloc(sizeof(char) * ft_strlen(*str) + 1);
	if (!flag)
	{
		while (**str && !ft_isspace(**str))
			a->raw[i++] = *(*str)++;
	}
	else if (flag)
	{
		a->raw[i++] = *(*str)++;
		while (**str && **str != flag)
			a->raw[i++] = *(*str)++;
		if (**str == flag)
			a->raw[i++] = *(*str)++;
		else if (**str == 0)
			ft_dquote(&a->raw, flag);
	}
}

void	parse_buffer_loop(char **str, t_array *array)
{
	while (**str && ft_isspace(**str))
		(*str)++;
	if (**str == 0)
		return ;
	if (**str == '\'' || **str == '"')
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


void	init_parse(char *buffer)
{
	t_array	*ptr;

	ptr = parse_buffer(buffer);
	print_tarrays(ptr);
}
