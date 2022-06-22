#include "../include/minishell.h"

void	shell_ll_to_envp(void)
{
	char	**old_envp;
	char	**new_envp;


	get_shell()->envp = new_envp;	
}

void	ll_add_content(t_ll **lst, char *name, char *content)
{
	t_ll	*tmp;
	t_ll	*l;
	
	l = *lst;
	if (l)
		printf("OK");
	tmp = NULL;
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
	if (!l)
		l = malloc(sizeof(t_ll));
	l->name = name;
	l->content = content;
	if (tmp)
		tmp->next = l;
	//printf("ll_add:%s=%s\n", l->name, l->content);
}


void	parse_envp_to_ll(char **e, t_ll *l)
{
	char	*name;
	char	*content;

	if (!e)
		return ;
	while (*e)
	{
		//find name/content 'name'='content'
		name = ft_strfdup(*e, '=');
		content = ft_strldupimp(*e, ft_strlen(name) + 1, ft_strlen(*e)); 
		//printf("%s = %s\n", name, content);	
		//export name, to find in list
		ll_add_content(&l, name, content);		
		e++;
	}
	printf("FINISHi---------------------\n\n");
}



void	shell_envp_to_ll(void)
{
	char	**envp;
	t_ll	*l;

	envp = get_shell()->envp;
	l = get_shell()->env;
	parse_envp_to_ll(envp, l);
}

t_shell	*get_shell(void)
{
	static t_shell	shell;
		
	return (&shell);
}

void	ft_minishell(t_shell *shell)
{
	//first step, create link list from envp
	shell_envp_to_ll();
	
	print_ll(shell->env);	
}

