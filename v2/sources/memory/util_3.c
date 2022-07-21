/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:35:09 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 14:26:22 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

/**
 * @brief 
 * 
 * @param pointer pointer to the block of memory to fill.
 * @param set value to be set. The value is passed as an int, but 
 * the function fills the block of memory using the unsigned char 
 * conversion of this value.
 * @param length number of bytes to be set to the value.
 * @return pointer to the memory area pointer.
 */
void	*_memory_set(void *pointer, int set, size_t length)
{
	size_t	index;

	index = 0;
	if (!pointer)
		return (NULL);
	while (index < length)
		*((unsigned char *)pointer + index++) = (unsigned char)set;
	return (pointer);
}

