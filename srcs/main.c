#include "../include/minishell.h"
/* NOTES N OBSERVATIONS
	
*/

int main(int argc, char **argv, char **envp)
{
	char 	*buff;
	char	**buff_array;
	t_shell	*shell;
	t_tkn	*tkn;

	shell = get_shell();
	shell->ec = -22;
	parse_envp_to_ll(envp, &shell->env);

	// char *cmd;
	// cmd = "ls";
	// ft_pipe(cmd, argv);

	if (argc != 1)
		return (ERROR_127);
	init_termios_n_signal();

	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		if (ft_strlen(buff) != 0)
		{
			add_history(buff);
			buff_array = buffer_into_array(buff);

			tkn = array_into_tokens(buff_array);
			// print_arrays(buff_array);
			// printf("--\n");
			// print_tkn(tkn);

			ft_exec(tkn);

			free_arrays(buff_array);
		}
		free(buff);
	}
}


/*
Goals
- ls ../


ENVP


*/