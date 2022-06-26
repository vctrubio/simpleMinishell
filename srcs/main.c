#include "../include/minishell.h"
/* NOTES N OBSERVATIONS
-
*/

static void	init_shell(char **envp)
{
	t_shell	*shell;

	shell = get_shell();
	shell->ec = -1;
	shell->count_tkn = 0;
	parse_envp_to_ll(envp, &shell->env);
	init_termios_n_signal();
}

int main(int argc, char **argv, char **envp)
{
	char 	*buff;
	char	**buff_array;

	if (argc != 1)
		return (ERROR_127);
	//INIT shell
	init_shell(envp);


	//MAIN LOOP
	while (42)
	{
		//step 1, READ
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		if (ft_strlen(buff) != 0)
		{
			//step 2, PARSE
			add_history(buff);
			buff_array = buffer_into_array(buff);
			array_into_tokens(buff_array);

			//PRINT FOR DEBUGGIN
			print_arrays(buff_array);
			// printf("--\n");
			// print_tkn(tkn);

			//step 3, EXECUTE
			// ft_validate();
			// ft_exec();

			//step 4, free
			free_arrays(buff_array);
		}
		free(buff);
	}
	return (0);
}


/*
The return status is the exit status of the last command executed.
parse_array - parses single and double quotes and $, just don't know when and where to use it
*/