/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:41 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:42 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/memory.h"

void *_memory_calloc(size_t count, size_t size)
{
    void *temp;

    temp = _memory().malloc(count * size);
    if (!temp)
        return (NULL);
    (_memory().set)(temp, '\0', count * size);
    return (temp);
}
