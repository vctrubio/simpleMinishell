#include "../include/minishell.h"
void  print_ll(t_ll *v);
void	print_arrays(char **a);

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

void	print_tarrays(t_array *a)
{
	while (a)
	{
    if (a->content)
	  	printf("content:%s\n", a->content);
    // if (a->linked)
    //   printf("notnull\n");
        // printf("is linked with %s |", a->linked->content);
    // printf("sq:%d|dq:%d|jn:%d\n", a->single_quote, a->db_quote, a->join_next);
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


void  print_tkn(t_tkn *t)
{
  int         i;

  if (!t)
    return ;
  printf("-print_tkn-*\n");
  // printf("%d|%d ", t->cmd->s_quote, t->cmd->d_quote);
  printf("CMD:%s\n", t->cmd->content);
  i = 0;
  while(t->args[i])
  {
    if (t->args[i])
    // printf("%d|%d ", t->args[i]->s_quote, t->args[i]->d_quote);
      printf("a%d:%s-\n", i, t->args[i]->content);
    i++;
  }
  if (t->next != NULL)
    print_tkn(t->next);
}
