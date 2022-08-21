/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:44 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:45 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void _memory_add(t_node_malloc *malloc)
{
	t_node_malloc **list;

	list = _memory_list();
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
