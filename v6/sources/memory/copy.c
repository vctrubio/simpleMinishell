/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:38 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:39 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void *_memory_copy(void *dst, const void *src, size_t size)
{
    size_t index;

    index = -1;
    if (!(char *)(dst) || !(char *)(src))
        return (dst);
    while (++index < size)
        ((char *)(dst))[index] = ((char *)(src))[index];
    return (dst);
}
