/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:39:02 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:39:03 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

int _string_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str1 && !*str2);
}

int _string_beginning_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str2);
}
