#include "../includes/minishell.h"

t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}

//0R

/*

t_shell	**_shell(void)
{
	static t_shell	*shell;

	return (&shell);

}




t_env	**_env(void)
{
	static t_env	*env;

	return (&env);
}


*/