/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:39:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:39:14 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

int _string_contains(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1)
		if (_string().beginning_equals(str1++, str2) > 0)
			return (1);
	return (0);
}
