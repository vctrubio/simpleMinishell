#ifndef STATIC_H
# define STATIC_H

# include "string.h"

typedef struct s_minishell
{
	t_hashmap	*env;	//link_list to save envps
	int			ec; //exitcode
}		t_shell;

t_shell	*get_shell(void);


# endif
