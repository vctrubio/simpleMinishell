/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:34 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:35 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

size_t _env_size(void)
{
	size_t size;
	t_node_env *env;

	size = 0;
	env = *_env().list();
	while (env)
	{
		env = env->next;
		size++;
	}
	return (size);
}
