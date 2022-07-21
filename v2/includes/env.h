/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:57:42 by joaribei          #+#    #+#             */
/*   Updated: 2022/06/28 22:57:56 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "string.h"

typedef struct s_env
{
	t_hashmap		*hashmap;
	struct s_env	*next;
}	t_env;

t_env		**_env(void);
t_hashmap	*get_env(char *key);
void		init_env(t_hashmap *hashmap);

#endif
