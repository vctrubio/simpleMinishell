/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:44 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:45 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"
#include <stdio.h>

t_node_env *_env_print(int signal)
{
	t_node_env *env;

	env = *_env().list();
	while (env)
	{
		if (signal && env->signal)
		{
			if (env->value)
				printf("%s=%s\n", env->key, env->value);
			else
				printf("%s=\n", env->key);
		}
		if (!signal)
		{
			printf("declare -x %s", env->key);
			if (env->signal && env->value)
				printf("=%s\n", env->value);
			if (env->signal)
				printf("=\"\"");
		}
		env = env->next;
	}
	return (NULL);
}
