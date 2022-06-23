#include "../include/minishell.h"

static void handle_ctrlc(int sig)
{
	(void)sig;

	write(1, "\n", 2);
	// rl_replace_line("", 0); this is commented because if not it gives error
	rl_on_new_line();
	rl_redisplay();
}

void	init_termios_n_signal(void)
{
	struct termios	term;

	signal(SIGINT, handle_ctrlc);
	if (tcgetattr(STDIN_FILENO, &term) != 0)
	{
		perror("tcgetattr() error");
		exit(101);
	}
	else
	{
		term.c_lflag &= ~(ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
	}
}

