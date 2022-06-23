#include "../include/minishell.h"

t_array	*rtn_t_array(void)
{
	t_array	*array;

	array = malloc(sizeof(array)); //try calloc
	array->raw = NULL;
	array->content = NULL;
	array->exepath = NULL;
	array->next = NULL;
	return (array);
}
