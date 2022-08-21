/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:20 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 18:30:01 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

void	_builting_add(t_node_builting *node)
{
	t_node_builting	**list;

	list = _builting_list();
	if (!*list)
		*list = node;
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = node;
		node->prev = *list;
	}
}

void	_command_add(t_node_command *node)
{
	t_node_command	**list;

	list = _command_list();
	if (!*list)
		*list = node;
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = node;
		node->prev = *list;
	}
}
