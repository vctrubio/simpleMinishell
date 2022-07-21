/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:33:26 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 02:42:59 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

t_malloc	**__malloc(int option)
{
	static t_malloc	*first;
	static t_malloc	*last;

	if (option)
		return (&last);
	return (&first);
}

void	_memory_add_maloc(t_malloc **new_malloc)
{
	if (!(*__malloc(0)))
	{
		(*__malloc(0)) = (*new_malloc);
	}
	else
	{
		(*__malloc(1)) = (*__malloc(0));
		while ((*__malloc(1))->next)
			(*__malloc(1)) = (*__malloc(1))->next;
		(*new_malloc)->prev = (*__malloc(1));
		(*__malloc(1))->next = (*new_malloc);
	}
	(*__malloc(1)) = (*new_malloc);
}

// return 0 if pointer have made a new malloc
// return 1 if pointer have been freed
int	_memory_free(void *ptr)
{
	if (ptr)
	{
		(*__malloc(1)) = (*__malloc(0));
		while ((*__malloc(1)))
		{
			if ((*__malloc(1))->ptr == ptr)
				break ;
			(*__malloc(1)) = (*__malloc(1))->next;
		}
		if (!(*__malloc(1)))
			return (1);
		free((*__malloc(1))->ptr);
		if ((*__malloc(1))->prev && (*__malloc(1))->next)
		{
			(*__malloc(1))->prev->next = (*__malloc(1))->next;
			(*__malloc(1))->next->prev = (*__malloc(1))->prev;
		}
		else if (!(*__malloc(1))->prev)
			(*__malloc(0)) = (*__malloc(0))->next;
		else if (!(*__malloc(1))->next)
			(*__malloc(1))->prev->next = NULL;
		free((*__malloc(1)));
	}
	return (0);
}

int	_memory_free_all(void)
{
	int	error;

	error = 0;
	(*__malloc(1)) = (*__malloc(0));
	while ((*__malloc(1))->next)
		(*__malloc(1)) = (*__malloc(1))->next;
	while ((*__malloc(1)))
	{
		error += _memory_free((*__malloc(1))->ptr);
		(*__malloc(1)) = (*__malloc(0));
		while ((*__malloc(1))->next)
			(*__malloc(1)) = (*__malloc(1))->next;
	}
	return (error);
}

t_malloc	*_memory_find_maloc(void *ptr)
{
	(*__malloc(1)) = (*__malloc(0));
	while ((*__malloc(1)))
	{
		if ((*__malloc(1))->ptr == ptr)
			return ((*__malloc(1)));
		(*__malloc(1)) = (*__malloc(1))->next;
	}
	return (NULL);
}
