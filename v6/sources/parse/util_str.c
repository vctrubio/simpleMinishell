/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:40:35 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:40:36 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/char.h"

void _stradd(char **str, char *add)
{
	int i;

	if (*str == NULL)
		return;
	i = 0;
	while ((*str)[i])
		i++;
	(*str) = realloc((*str), _string().length(*str) + _string().length(add) + 1);
	while (*add)
	{
		(*str)[i++] = *add;
		add++;
	}
	(*str)[i] = 0;
}

int _strcount_char(char *str, char l)
{
	int i;

	i = 0;
	if (!str || !l)
		return (0);
	while (*str)
	{
		if (*str == l)
			i++;
		str++;
	}
	return (i);
}

int r_size(char *s)
{
	int is_special;
	int size;

	size = 0;
	is_special = -1;
	while (s && *s)
	{
		if (_char().is_whitespace(*s))
		{
			if (is_special != 0)
				is_special = 0;
		}
		else if (_char().is_special_parse(*s))
		{
			is_special = 1;
			size++;
		}
		else
		{
			if (is_special != 2)
			{
				is_special = 2;
				size++;
			}
		}
		s++;
	}
	return (size);
}
