#include "../include/minishell.h"

void	enum_tkn(t_tkn *t)
{
	if (ft_strexact(t->cmd->content, "<<"))
		t->type = IS_HEREDOC;
	else if (ft_strexact(t->cmd->content, "<"))
		t->type = IS_RDR_IN;
	else if (ft_strexact(t->cmd->content, ">"))
		t->type = IS_RDR_OUT;
	else if (ft_strexact(t->cmd->content, "|"))
		t->type = IS_PIPE;
	else  
		t->type = IS_CMD;
	
}

void	parse_token_loop(t_array **a, t_tkn *tkn)
{
	// printf("here %s\n", (*a)->content);
	int	i;

	i = 0;
	tkn->cmd = (*a);
	enum_tkn(tkn);
	(*a) = (*a)->next;
	if (!(*a))
		return ;
	while ((*a))
	{
		if (ft_strlook((*a)->content, "<>|")) //and no quotes)
			break;
		tkn->args[i++] = (*a);
		(*a) = (*a)->next;
	}
	tkn->args[i] = 0;
	return ;
}


void	parse_to_token(t_array *a)
{
	t_tkn	*head;
	t_tkn	*next;
	t_tkn	*prev;

	head = rtn_token();
	parse_token_loop(&a, head);
	prev = NULL;
	while (a)
	{
		if (!a)
			break;
		next = rtn_token();
		parse_token_loop(&a, next);
		if (prev)
			prev->next = next;
		if (head->next == NULL)
			head->next = next;
		prev = next;		
	}
	get_shell()->tkn = head;
	print_tkn(get_shell()->tkn);
}



void	init_parse(char *buffer)
{
	t_array	*ptr;

	ptr = parse_buffer(buffer);
	ft_store_tarry(ptr);
	parse_to_token(ptr);
	//validate_token();

	// print_tarrays(ptr);
}
