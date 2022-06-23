#include "../include/minishell.h"

typedef struct s_token
{
	char	*cmd;
	char	*path;
	char	*args;
	e_type	type;
	struct s_token	*next;
}				t_token;


char	*parse_array(char *str)
{
	t_ll	*env;

//FIND the missing piece, init env

}


void	array_into_tokens(char **a) // return false if error
{
	//HERE
	//goal, try and ge heredoc input
	int		i;
	char	*ptr;

	i = 0;
	while(a[i])
	{
		ptr = parse_array(a[i]);
		i++;
	}

}


int main(int argc, char **argv, char **envp)
{
	char 	*buff;
	char	**buff_array;

	if (argc != 1)
		return (ERROR_127);
	init_termios_n_signal();
	//init_global_static
	while (42)
	{
		buff = readline("$>");
		if (ft_strexact(buff, "exit"))
			break;
		buff_array = buffer_into_array(buff);
		// print_arrays(buff_array);

		array_into_tokens(buff_array);


		//validate
		free_str(buff);
		// free_arrays(buff_array);
	}
}


/*





*/