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

typedef enum	e_pipe_cmd //pipecommad
{
	RDR_IN,
	RDR_OUT,
	RDR_APP,
	RDR_HRE,
}				e_p;

typedef struct	s_pipe
{
	int		fd[2];
	int		pid;
	e_p		pcmd;
}				t_pipe;


typedef enum	e_type
{
	NOTVALID,
	IS_CMD,
	IS_BUILTIN,
	IS_RDR,
	IS_PIPE,
	IS_PATH,
	IS_SQUOTE,
	// IS_ENV,
	// SKIP,
}				e_type;

typedef struct	s_linklist
{
	char				*name;
	char				*content;
	struct s_linklist	*next;
}				t_ll;

typedef struct	s_token
{
	char			*cmd;
	char			**args;
	char			*cmd_path;
	e_type			type;
	struct s_token	*next;
}				t_tkn;

typedef struct s_minishell
{
	char	**envp;	//envp used for execution
	// t_ll	*var;	//used for local var ie: $var=variables
	t_ll	*env;	//link_list to save envps
	t_tkn	*tkn;
	int		count_tkn;
	int	ec; //exitcode
}		t_shell;

//minishell
t_shell		*get_shell(void);
void		ft_minishell(void);
//minishell2.0
char	**ft_list_to_array(t_list *l);
//execute
void	ft_exec(void);
//parse
void	init_parse(char *buffer);
//parseArray
void	dollar_for_money(char **out, char **str);
char	*parse_array(char *str);
//parseBuffer
char	*buffer_quotes(char **buff, char c, char *str, int i);
char	*buffer_scan_for_quotes(char *str);
char	*buffer_to_string(char **buff);
char	**buffer_into_array(char *str);
//parseToken
e_type	ft_enum_token(char *t);
bool	ft_special_char(char *str);
t_tkn	*ft_evalute_single_token(char **a, int *index);
void	array_into_tokens(char **array);

//memoryMalloc
t_tkn	*rtn_token(char *cmd);
//signals
void	init_termios_n_signal(void);
//free
void	free_str(char *str);
void	free_arrays(char **arr);
//dquote
void	ft_dquote(char **str, char c);
//prompt
char	*get_usr(void);
char	*ft_prompt(void);
//heredoc
void	ft_create_heredoc(char *eof);
void	scan_for_heredoc(void);
//staticCalls
t_shell	*get_shell(void);

//pipex
char	*find_cmd_path(char *str);
int ft_pipe(char *cmd, char **agv);
//validate
void	ft_validate(void);

//utilStrExact
int  	ft_strcount_char(char *str, char l);
bool  	ft_strlook(char *str, char *look);
bool	ft_strexact(char *s1, char *s2);
bool	ft_strexact_abs(char *s1, char *s2);
bool	ft_isspace(char c);
//utilStrFind
char	*ft_strldupimp(char *str, int i, int j);
char	*ft_strldup(char *str, int l);
char	*ft_strfdup(char *str, int f);
int		r_size(char *s);
bool	ft_isquote(char c);
//utilsStr
void 		ft_stradd(char **str, char *add);
int			count_words(char *str, char c);
char		**ft_strsplit(char const *str, char c);
//utilPrint
void 	print_arrays(char **a);
void	print_ll(t_ll *v);
void  print_tkn(t_tkn *t);
//utilsLinkList
int		ll_size(t_ll *l);
t_ll	*rtn_ll(char *name, char *content);
void	ll_add_content(t_ll **head, char *name, char *content);
//utilsENVP
void	shell_ll_to_envp(void);
void	parse_envp_to_ll(char **e, t_ll **l);
void	ft_shell_envp_to_ll(void);
char	*rtn_envp_from_ll(t_ll *l);
char		*parse_var_env(char *str);




#endif
