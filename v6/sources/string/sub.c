/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:36:02 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:37:39 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char *_string_sub(char *string, size_t start, size_t end)
{
	size_t lenght;
	size_t index;
	char *new_string;

	lenght = _string().length(string);
	if (!string || start > end || start > lenght || end > lenght)
		return (0);
	new_string = _memory().calloc(end - start + 1, sizeof(char));
	index = -1;
	while (++index < end - start)
		new_string[index] = string[start + index];
	return (new_string);
}
