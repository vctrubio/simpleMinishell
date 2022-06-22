#include "../include/minishell.h"
int		ll_size(t_ll *l);
t_ll	*rtn_ll(char *name, char *content);
void	ll_add_content(t_ll **head, char *name, char *content);

int	ll_size(t_ll *l)
{
	int	i;

	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_ll	*rtn_ll(char *name, char *content)
{
	t_ll	*l;
	//printf("name%s %s \n", name, content);

	l = malloc(sizeof(t_ll));
	if (name)
		l->name = name;
	if (content)
		l->content = content;
	l->next = NULL;
	return (l);
}

void	ll_add_content(t_ll **head, char *name, char *content)
{
	t_ll	*tmp;
	t_ll	*l;

	l = *head;
	tmp = NULL;
	if (!l)
	{
		*head = rtn_ll(name, content);
		return ;
	}
	while (l)
	{
		if (ft_strexact(l->name, name))
		{
			l->content = content;
			return ;
		}
		tmp = l;
		l = l->next;
			
	}
	l = rtn_ll(name, content);
	if (tmp)
		tmp->next = l;
}