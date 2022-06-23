#include "../include/minishell.h"
t_shell	*get_shell(void);
t_array *ft_store_tarry(t_array *a);

t_array *ft_store_tarry(t_array *a)
{
	static t_array storage;

	if (a)
		storage = *a;
	return (&storage);
}


t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}
