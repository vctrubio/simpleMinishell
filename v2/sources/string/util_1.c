/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:20:19 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 14:01:16 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

//returns 1 if the strings are the same, or zero if they are different
int	_string_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str1 && !*str2);
}

int	_string_beginning_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str2);
}

int	_string_contains(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1)
		if (_string().equals(str1++, str2))
			return (1);
	return (0);
}

/*
 * returns the index of the first occurence of the substring 
 * within the string.returns -1 if the substring is not found.
 */
int	_string_index_of(char *string_1, char *string_2)
{
	int	i;
	int	j;

	if (!string_1 || !string_2)
		return (-1);
	i = -1;
	while (string_1[++i])
	{
		j = -1;
		while (string_2[++j])
			if (string_1[i + j] != string_2[j])
				break ;
		if (!string_2[j])
			return (i);
	}
	return (-1);
}
