#include "../include/minishell.h"
void  print_ll(t_ll *v);
void	print_arrays(char **a);
void  print_tkn(t_tkn *t);

void	print_arrays(char **a)
{
  int i;

  i = 0;
	while(a[i])
  {
    if (a[i])
     if (ft_strlen(a[i]) == 0)
      break;
		printf("%s\n", a[i++]);
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

void  print_tkn(t_tkn *t)
{
  int         i;

  if (!t)
    return ;
  printf("CMD: %s\n", t->cmd);
  i = 0;
  while(t->args[i])
  {
    if (t->args[i])
      printf("a%d: %s -\n", i, t->args[i]);
    i++;
  }
  if (t->next != NULL)
    print_tkn(t->next);
}
