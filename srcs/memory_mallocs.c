#include "../include/minishell.h"

t_array	*rtn_t_array(void)
{
	t_array	*array;

	array = malloc(sizeof(array)); //try calloc
	array->content = NULL;
	array->next = NULL;
	array->linked = NULL;
	return (array);
}


