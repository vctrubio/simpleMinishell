#include "../include/minishell.h"

void	shell_ll_to_envp(void);
void	parse_envp_to_ll(char **e, t_ll **l);
void	shell_envp_to_ll(void);
char	*rtn_envp_from_ll(t_ll *l);
char	*parse_var_env(char *str);


char		*parse_var_env(char *str)
{
	t_ll	*lst;

	lst = get_shell()->env;
	while (lst)
	{
		// printf("Search |%s|%s|\n", str, lst->name);
		if (ft_strexact(str, lst->name))
			return (lst->content);
		lst = lst->next;
	}
	return ("");
}



char	*rtn_envp_from_ll(t_ll *l)
{
	char	*tmp;
	char	*str;
	
	tmp = ft_strdup(l->name);
	tmp = ft_strjoin(tmp, "=");
	str = ft_strjoin(tmp, l->content);
	free_str(tmp);
	return (str);
}


void	shell_ll_to_envp(void)
{
	char	**old_envp;
	char	**new_envp;
	int	i;
	t_ll	*l;

	l = get_shell()->env;
	old_envp = get_shell()->envp;
	*new_envp = malloc(sizeof(char) * ll_size(l));
	i = 0;
	while (l)
	{	
		new_envp[i++] = rtn_envp_from_ll(l);	
		l = l->next;
	}
	//print_arrays(new_envp); working
}

void	parse_envp_to_ll(char **e, t_ll **l)
{
	char	*name;
	char	*content;
	
	if (!e)
		return ;
	while (*e)
	{
		//find name/content 'name'='content'
		name = ft_strfdup(*e, '=');
		content = ft_strldupimp(*e, ft_strlen(name) + 1, ft_strlen(*e)); //printf("%s = %s\n", name, content);	
		//export name, to find in list
		ll_add_content(l, name, content);
		e++;
	}
}

void	shell_envp_to_ll(void)
{
	char	**envp;
	t_ll	**l;

	envp = get_shell()->envp;
	l = &get_shell()->env;
	parse_envp_to_ll(envp, l);
}
