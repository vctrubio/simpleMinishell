#include "../includes/minishell.h"
/* FOR DEBUGGING */

void	print_arrays(char **a)
{
  int i;
	char *tmp;
  i = 0;
	while(a[i])
	{
		tmp = parse_array(a[i++]);
	  printf("%s\n", tmp);
	}
}
