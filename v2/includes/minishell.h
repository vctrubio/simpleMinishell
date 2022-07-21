/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:08 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 16:58:53 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <termios.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>

# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

# include "string.h"
# include "command.h"
# include "env.h"
# include "parse.h"
# include "prompt.h"
# include "static.h"
# include "signl.h"

#endif
