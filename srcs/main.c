#include "../include/minishell.h"

static int	init_minishell(char **envp)
{
	int		exitcode;
	t_shell	*shell;
	
	shell = get_shell();
	shell->envp = envp;
	ft_minishell();
	exitcode = shell->ec;
	//free ....
	printf("exit code: %d\n", shell->ec);
	return (exitcode);
}

int main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (ERROR_127);
	init_termios_n_signal();
	return (init_minishell(envp));
}
