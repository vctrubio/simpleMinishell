/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:36:12 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:37:55 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char *_string_replace(char *str, int start, int end, char *new)
{
	int index;
	int length;
	char *new_string;

	index = -1;
	length = _string().length(str + ((end + 1) - start));
	length += _string().length(new);
	new_string = _memory().calloc(sizeof(char), length + 1);
	while (++index < start)
		new_string[index] = str[index];
	while (new &&*new)
		new_string[index++] = *(new ++);
	while (str && str[++end])
		new_string[index++] = str[end];
	_memory().free(str);
	return (new_string);
}
