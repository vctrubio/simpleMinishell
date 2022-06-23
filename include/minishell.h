/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrito-l <cbrito-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:59:01 by cbrito-l          #+#    #+#             */
/*   Updated: 2022/03/20 17:59:01 by cbrito-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include <termios.h>
#include <errno.h>

// error codes
# define SUCESS 0
# define ERROR 1
# define IS_DIRECTORY 126
# define ERROR_127 127

typedef struct	s_array
{
	char			*raw; //with quotes
	char			*content; //clean- parsed
	char			*exepath; //executable path, if any
	struct s_array	*next;
}				t_array;

typedef enum	e_type
{
	IS_CMD,
	IS_RDR,
	IS_PIPE,
	IS_VAR,
	IS_ENV,
	SKIP,
}				e_type;

typedef struct	s_linklist
{
	char				*name;
	char				*content;
	struct s_linklist	*next;
}				t_ll;

typedef struct	s_token
{
	t_array			*cmd;
	t_array			*args;
	e_type			type;
	struct s_token	*next;
}				t_tkn;


typedef struct s_minishell
{
	char	**envp;	//envp used for execution
	t_ll	*var;	//used for local var ie: $var=variables
	t_ll	*env;	//link_list to save envps
	t_tkn	*tkn;
	int	ec; //exitcode
}		t_shell;

//minishell
t_shell		*get_shell(void);
void		ft_minishell(void);
//minishell2.0
char	**ft_list_to_array(t_list *l);
//memory_mallocs.c

//parse
void	init_parse(char *buffer);
//memoryMalloc
t_array	*rtn_t_array(void);
//signals
void	init_termios_n_signal(void);
//free
void	free_str(char *str);
void	free_arrays(char **arr);
//dquote
void	ft_dquote(char **str, char flag);
//prompt
char	*get_usr(void);
char	*ft_prompt(void);

//utilStrExact
bool  	ft_strlook_char(char *str, char l);
bool  	ft_strlook(char *str, char *look);
bool	ft_strexact(char *s1, char *s2);
bool	ft_strexact_abs(char *s1, char *s2);
bool	ft_isspace(char c);
//utilStrFind
char	*ft_strldupimp(char *str, int i, int j);
char	*ft_strldup(char *str, int l);
char	*ft_strfdup(char *str, int f);
//utilPrint
void 	print_arrays(char **a);
void	print_tarrays(t_array *a);
void	print_ll(t_ll *v);
//utilsLinkList
int		ll_size(t_ll *l);
t_ll	*rtn_ll(char *name, char *content);
void	ll_add_content(t_ll **head, char *name, char *content);
//utilsENVP
void	shell_ll_to_envp(void);
void	parse_envp_to_ll(char **e, t_ll **l);
void	shell_envp_to_ll(void);
char	*rtn_envp_from_ll(t_ll *l);

/*
//utilMyUtil.c
bool  	no_quotes(t_array *a);
char	*ft_strldupimp(char *str, int i, int j);
char	*ft_strldup(char *str, int l);
char	*ft_strfdup(char *str, int f);
bool 	ft_strlook(char *str, char *look);
bool  	ft_strlook_char(char *str, char l);
bool	ft_strexact(char *s1, char *s2);
bool	ft_strexact_abs(char *s1, char *s2);
void	vars_to_array(t_args **arr, t_var *var);
void 	ft_stradd(char **str, char *add);

//utilPrint
void  print_arrays(char **a);
void  print_targs(t_args *a);
void  print_tkn(t_token *t);
void  print_var(t_var *v);
void  print_array(t_array *a);

//free
void	free_variables(t_var **vars);
void	free_str(char *str);
void	free_array(t_array **arr);
void	free_tokens(t_token **tokens);
int		free_minishell(t_minishell **shell);
void	free_arrays(char **arr);
*/

#endif
