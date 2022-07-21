#include "../../includes/minishell.h"

static void	sig_int(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "newline\n", 8);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		get_shell()->ec = 130;
	}
}



void	init_termios(void)
{
	struct sigaction	sa;
//	struct sigaction	sa_1;
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term);

	sa.sa_handler = &sig_int;
//	sa_1.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
//	sigaction(SIGQUIT, &sa, NULL);
	
	printf("hi termi\n");
}

/* handle

◦ ctrl-C displays a new prompt on a new line. 
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing.
*/
