/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:36:21 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:38:08 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

size_t _string_length(char *string)
{
    size_t length;

    length = 0;
    if (string)
        while (string[length])
            ++length;
    return (length);
}
