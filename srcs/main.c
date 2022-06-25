#include "../include/minishell.h"
/*
	look for |<>
*/

int main(int argc, char **argv, char **envp)
{

	t_shell	*shell;
	shell = get_shell();
	shell->ec = -22;
	parse_envp_to_ll(envp, &shell->env);
	
	// char *cmd;
	// cmd = "ls";
	// ft_pipe(cmd, argv);

	char 	*buff;
	char	**buff_array;
	t_tkn	*tkn;

	if (argc != 1)
		return (ERROR_127);
	init_termios_n_signal();

	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		add_history(buff);
		// parse_array(buff);
		printf("%s\n", parse_array(buff));
		// buff_array = buffer_into_array(buff);

		// // print_arrays(buff_array);
		// tkn = array_into_tokens(buff_array);
		// // print_tkn(tkn);

		// ft_exec(tkn);
	
		// //validate
		// free_str(buff);
		free(buff_array);
		buff_array = NULL;
		// free_arrays(buff_array);
	}
}


/*
Goals
- ls
- ../ ls


ENVP


*/