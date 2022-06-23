#include "../include/minishell.h"
void  print_ll(t_ll *v);
void	print_arrays(char **a);

void	print_arrays(char **a)
{
	while(*a)
	{
		printf("%s\n", *a);
		a++;
	}
}

void	print_tarrays(t_array *a)
{
	while (a)
	{
    if (a->raw)
	  	printf("raw:%s\n", a->raw);
    // if (a->content)
		//   printf("content:%s\n", a->content);
    // if (a->exepath)
	  // 	printf("exe:%s\n", a->exepath);
		a = a->next;
	}
}

void  print_ll(t_ll *v)
{

  if (!v)
	{
		printf("list empty\n");
		return ;
	}
  printf("-linklist-*\n");
  int i = 0;
  while (v)
  {
    printf("name%d:%s\n", i, v->name);
    printf("content%d:%s\n", i, v->content);
    v = v->next;
    i++;
  }
  printf("--*\n");
}


