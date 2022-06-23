#include "../include/minishell.h"

void	free_str(char *str)
{
	// printf("free_str:%s\n", str);
	if (!str)
		return ;
	free(str);
	str = NULL;
}

void	free_arrays(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free_str(arr[i]);
		i++;
	}
}

void	free_tarrays(t_array **t)
{
	t_array	*ptr;
	t_array	*next;

	ptr = *t;
	while (ptr)
	{
		if (ptr->content)
			free_str(ptr->content);
		next = ptr->next;
		free(ptr);
		ptr = NULL;
	}
}
