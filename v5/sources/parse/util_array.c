#include "../../includes/parse.h"

// void	free_str(char *str)
// {
// 	if (!str)
// 		return ;
// 	free(str);
// 	str = NULL;
// }

void	free_arrays(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		_memory().free(arr[i]);
		arr[i++] = NULL;
	}
	_memory().free(arr);
	arr = NULL;
}
