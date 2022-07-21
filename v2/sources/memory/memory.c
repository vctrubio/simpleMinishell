/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:53:46 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 14:27:38 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

t_memory	_memory(void)
{
	static t_memory	_memory = {
		_memory_free_all,
		_memory_free,
		_memory_malloc,
		_memory_realloc,
		_memory_calloc,
		_memory_set,
		_memory_copy
	};

	return (_memory);
}
