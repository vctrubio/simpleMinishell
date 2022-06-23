#include "../include/minishell.h"

t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}

void	ft_minishell()
{
	char	*buff;
	char	*usr;

	//first step, create link list from envp
	shell_envp_to_ll();
	usr = get_usr();
	printf("WELCOME %s to MINISHELL\n", usr);
	buff = NULL;
	while (42)
	{
		//READLINE
		buff = readline(ft_prompt());
		if (!ft_strexact(buff, ""))
		{
			add_history(buff);
			if (ft_strexact(buff, "exit")) //  & clear
				break;
			init_parse(buff);
			//TOKEN

			//EXECUTE

			//FREE
			// free_str(buff);
		}
	}


	// t_ll *l;
	// l = get_shell()->env;
	//printf("%s --\n", rtn_envp_from_ll(l));	
}

