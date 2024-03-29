/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:24 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 08:04:34 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

t_memory	_memory(void)
{
	static t_memory	_memory = {
		_memory_malloc,
		_memory_realloc,
		_memory_calloc,
		_memory_free,
		_memory_free_all,
		_memory_set,
		_memory_copy};

	return (_memory);
}

t_node_malloc	**_memory_list(void)
{
	static t_node_malloc	*command;

	return (&command);
}
