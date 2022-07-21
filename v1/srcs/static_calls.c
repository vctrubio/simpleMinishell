#include "../include/minishell.h"
t_shell	*get_shell(void);

t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}
