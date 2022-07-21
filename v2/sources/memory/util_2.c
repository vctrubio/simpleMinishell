/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:35:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 02:42:36 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

/**
 * @brief 
 * 
 * @param count The number of elements of array to be allocated.
 * @param size Size of allocated memory in bytes.
 * @return returns a pointer to the allocated memory, or NULL if 
 * the request fails.
 */
void	*_memory_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	(_memory().set)(temp, '\0', count * size);
	return (temp);
}

void	*_memory_malloc(size_t __size)
{
	t_malloc		*node;

	node = malloc(sizeof(t_malloc));
	if (!node)
	{
		perror("error _memory_malloc");
		_memory().free_all();
		exit(EXIT_FAILURE);
	}
	node->size = __size;
	node->prev = NULL;
	node->next = NULL;
	node->ptr = malloc(__size);
	if (!node->ptr)
	{
		free(node);
		_memory().free_all();
		perror("error _memory_malloc");
		exit(EXIT_FAILURE);
	}
	_memory_add_maloc(&node);
	return (node->ptr);
}

void	*_memory_realloc(void *ptr, size_t size)
{
	t_malloc	*node;
	void		*temp;

	node = _memory_find_maloc(ptr);
	if (!node)
	{
		perror("error realloc");
		exit(EXIT_FAILURE);
	}
	temp = _memory().malloc(node->size + size);
	(_memory().copy)(temp, ptr, node->size);
	_memory().free(node->ptr);
	return (temp);
}

void	*_memory_copy(void *dst, const void *src, size_t size)
{
	size_t	index;

	index = -1;
	if (!(char *)(dst) || !(char *)(src))
		return (dst);
	while (++index < size)
		((char *)(dst))[index] = ((char *)(src))[index];
	return (dst);
}
