/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:51 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <stdio.h>

static void _delete(t_node_env *node_env)
{
	if (node_env)
	{
		_memory().free(node_env->key);
		_memory().free(node_env->value);
		if (node_env->next)
			node_env->next->prev = node_env->prev;
		if (node_env->prev)
			node_env->prev->next = node_env->next;
		_memory().free(node_env);
	}
}

void _env_delete(char *key)
{
	t_node_env *env;

	env = *_env().list();
	while (env)
	{
		if (_string().equals(env->key, key))
		{
			_delete(env);
			return ;
		}
		env = env->next;
	}
}
