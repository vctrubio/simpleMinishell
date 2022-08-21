/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:08 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:09 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void _env_add(t_node_env *malloc);

void *_env_create(char *string)
{
	t_node_env *new_node;
	char		**split;

	new_node = _memory().calloc(1, sizeof(t_node_env));
	new_node->signal = _string().index_of(string, "=") > 0;
	split = _string().split_char(string, '=');
	new_node->key = split[0];
	new_node->value = split[1];
	_env_add(new_node);
	_memory().free(split);
	return (new_node);
}
