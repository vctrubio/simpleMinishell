#include "../../includes/parse.h"

void	print_arrays(char **a)
{
	int i;

	i = 0;
	while(a[i])
	{
		printf("%s\n", a[i++]);
	}
}
