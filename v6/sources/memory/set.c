/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:22 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:23 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void *_memory_set(void *pointer, int set, size_t length)
{
    size_t index;

    index = 0;
    if (!pointer)
        return (NULL);
    while (index < length)
        *((unsigned char *)pointer + index++) = (unsigned char)set;
    return (pointer);
}
