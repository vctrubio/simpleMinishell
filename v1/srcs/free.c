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
	free(arr);
	arr = NULL;
}

//MORE TO DO