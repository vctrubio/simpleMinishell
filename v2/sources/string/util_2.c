/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:26:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 02:19:00 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

// return the length of the string
size_t	_string_length(char *string)
{
	if (string && *string)
		return (1 + _string_length(++string));
	return (0);
}

t_hashmap	*_string_new_hashmap(char *string)
{
	t_hashmap	*new_hashmap;
	char		**split;

	new_hashmap = _memory().malloc(sizeof(t_hashmap));
	split = _string().split_char(string, '=');
	new_hashmap->key = split[0];
	new_hashmap->value = split[1];
	return (new_hashmap);
}
