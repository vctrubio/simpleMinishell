/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:58 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:44:59 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>

#include "memory.h"
#include "string.h"
#include "signal_r.h"
#include "command.h"
#include "parse.h"

typedef struct s_minishell
{
	char **env;
	char *pwd;
	char *home;
	int ec;
} t_shell;

t_shell *_shell(void);

#endif // DOBLY_LINKED_LIST_H
