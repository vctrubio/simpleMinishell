/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:27 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:28 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void *_memory_realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (!size)
        return (NULL);
    new_ptr = _memory().calloc(1, size);
    if (!new_ptr)
        return (new_ptr);
    _memory().copy(new_ptr, ptr, size);
    _memory().free(ptr);
    return (new_ptr);
}
