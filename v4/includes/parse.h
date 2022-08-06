
#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>

# include "char.h"
# include "string.h"
# include "minishell.h"
# include "env.h"

int		r_size(char *s);
void	_stradd(char **str, char *add);
int		_strcount_char(char *str, char l);
char	**buffer_into_array(char *str);
void	ft_dquote(char **output, char c);
void	free_arrays(char **arr); //this can go

char	*parse_clean(char *str);
void	print_arrays(char **a);

#endif
