/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:55 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:44:56 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>

# include "char.h"
# include "string.h"
# include "minishell.h"
# include "env.h"

typedef struct s_vars t_vars;

struct s_vars
{
	char* new;
	char *temp;
	char *env;
	int start;
	int index;
	int correction;
};

int		r_size(char *s);
void	_stradd(char **str, char *add);
int		_strcount_char(char *str, char l);
char	**buffer_into_array(char *str);
void	ft_dquote(char **output, char c);
void	free_arrays(char **arr); //this can go
char	*_parce_string_env(char *string);

char *parse_clean(char *str);
void	print_arrays(char **a);

#endif
