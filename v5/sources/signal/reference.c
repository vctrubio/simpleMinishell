#include "../../includes/signal_r.h"

void hendle_signal(int sig)
{
	(void)sig;
	write(1, "D\n", 2);
}

void hendle_ctrl_c(int sig)
{
	(void)sig;
	write(1, "C\n", 2);
}

void _signal(void)
{
	// signal(VINTR, hendle_signal);
	signal(SIGINT, hendle_ctrl_c);
}
