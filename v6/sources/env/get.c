/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:46 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:47 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <stdio.h>

t_node_env *_env_get(char *key)
{
	t_node_env *env;

	env = *_env().list();
	while (env)
	{
		if (_string().equals(env->key, key))
			return (env);
		env = env->next;
	}
	return (NULL);
}
