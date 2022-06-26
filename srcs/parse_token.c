#include "../include/minishell.h"
e_type	ft_enum_token(char *t);
bool	ft_special_char(char *str);
t_tkn	*array_into_tokens(char **array);
t_tkn	*ft_evalute_single_token(char **a, int *index);

bool	ft_special_char(char *str)
{
	if (str[0] == '<')
		return (true);
	if (str[0] == '>')
		return (true);
	if (str[0] == '|')
		return (true);
	return (false);
}

bool	ft_check_builtin(char *str)
{
	if (ft_strexact(str, "cd"))
		return (true);
	if (ft_strexact(str, "echo"))
		return (true);
	if (ft_strexact(str, "pwd"))
		return (true);
	if (ft_strexact(str, "export"))
		return (true);
	if (ft_strexact(str, "unset"))
		return (true);
	if (ft_strexact(str, "env"))
		return (true);
	return (false);
}



e_type	ft_enum_token(char *t)
{
	char	*str;
	char	*tmp;

	str = t;
	if (!str)
		return (NOTVALID);
	if (*str == '|')
		return (IS_PIPE );
	else if (*str == '<' || *str == '>')
		return (IS_RDR);
	else if (*str == '.' || *str == '/')
		return (IS_PATH);
	if (ft_check_builtin(str))
		return (IS_BUILTIN);
	return (IS_CMD);
}


t_tkn	*ft_evalute_single_token(char **a, int *index)
{
	t_tkn	*tkn;
	int		j;

	// printf("EVAL :%s\n", a[*index]); SOMETIMES IT DOESNT F SHOW
	tkn = rtn_token(a[*index]);
	(*index)++;
	tkn->type = ft_enum_token(tkn->cmd);
	// printf("cmd%s|enum%d\n", tkn->cmd, tkn->type);
	if (tkn->type == IS_RDR)
	{
		tkn->args[0] = a[*index];
		(*index)++;
		return (tkn);
	}
	return (tkn);
}

t_tkn	*array_into_tokens(char **array)
{
	t_tkn	*head;
	t_tkn	*next;
	t_tkn	*prev;
	int		i;
	int		j;

	i = 0;
	prev = NULL;
	j = 0;
	head = ft_evalute_single_token(array, &i);
	if (ft_enum_token(head->cmd) == IS_CMD)
	{
		while (array[i] && !ft_special_char(array[i]))
			head->args[j++] = parse_array(array[i++]);
	}
	while (array[i])
	{
		next = ft_evalute_single_token(array, &i);
		if (ft_enum_token(next->cmd) == IS_CMD)
		{
			j = 0;
			while (array[i] && !ft_special_char(array[i]))
				next->args[j++] = parse_array(array[i++]);
		}
		if (!head->next)
			head->next = next;
		else
			prev->next = next;
		prev = next;
	}
	// print_tkn(head);
	return (head);
}
