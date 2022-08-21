/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:38:58 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:38:59 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

int _string_index_of(char *str1, char *str2)
{
	int index;

	index = -1;
	if (!str1 || !str2)
		return (-2);
	while (str1[++index])
		if (_string().beginning_equals(str1 + index, str2) > 0)
			return (index);
	return (-1);
}
