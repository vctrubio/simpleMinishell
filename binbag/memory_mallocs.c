#include "../include/minishell.h"

t_array	*rtn_t_array(void)
{
	t_array	*array;

	array = malloc(sizeof(array)); //try calloc
	array->content = NULL;
	array->next = NULL;
	array->linked = NULL;
	array->s_quote = false;
	array->d_quote = false;
	return (array);
}

t_tkn	*rtn_token(void)
{
	t_tkn	*t;

	t = malloc(sizeof(t_tkn));
	t->next = NULL;
	t->args = malloc(sizeof(char) * 1000); //this can improve
	return (t);
}

