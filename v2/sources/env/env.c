/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:57:32 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 11:02:48 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <stdio.h>

t_env	**_env(void)
{
	static t_env	*env;

	return (&env);
}

t_hashmap	*get_env(char *key)
{
	t_env	*env;

	env = *_env();
	while (env)
	{
		if (_string().equals(env->hashmap->key, key))
			return (env->hashmap);
		env = env->next;
	}
	return (NULL);
}

void	init_env(t_hashmap *hashmap)
{
	t_env	**env;

	env = _env();
	if (!*env)
	{
		(*env) = (t_env *)_memory().malloc(sizeof(t_env));
		(*env)->hashmap = hashmap;
		(*env)->next = NULL;
	}
	else
	{
		while ((*env)->next)
			env = &(*env)->next;
		(*env)->next = (t_env *)_memory().malloc(sizeof(t_env));
		(*env)->next->hashmap = hashmap;
		(*env)->next->next = NULL;
	}
}
