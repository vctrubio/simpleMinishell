/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:14 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void _env_add(t_node_env *malloc)
{
	t_node_env **list;

	list = _env().list();
	if (!*list)
		*list = malloc;
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = malloc;
		malloc->prev = *list;
	}
}
