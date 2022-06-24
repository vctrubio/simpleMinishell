#include "../include/minishell.h"

typedef struct s_tokens
{
	char	*cmd;
	char	*path;
	char	*args;
	e_type	type;
	struct s_token	*next;
}				t_tokens;




int main(int argc, char **argv, char **envp)
{
	char 	*buff;
	char	**buff_array;
	t_shell	*shell;

	if (argc != 1)
		return (ERROR_127);
	init_termios_n_signal();
	shell = get_shell();
	shell->ec = -22;
	parse_envp_to_ll(envp, &shell->env);

	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		add_history(buff);
		buff_array = buffer_into_array(buff);
		// print_arrays(buff_array);
		
		// array_into_tokens(buff_array);
		ft_exec(buff_array);

		//validate
		free_str(buff);
		// free_arrays(buff_array);
	}
}


/*
Goals
- ls
- ../ ls


ENVP


*/