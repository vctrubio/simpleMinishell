/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:13:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 02:08:49 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char	*_string_dup(const char *string)
{
	char	*new_string;
	int		len;

	len = _string().length((char *)string);
	new_string = _memory().calloc((len + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	while (*string)
		*new_string++ = *string++;
	new_string -= len;
	return (new_string);
}

char	*_string_dup_at(const char *string, size_t size)
{
	size_t	index;
	char	*new_string;

	if (size > _string().length((char *)string))
		size = _string().length((char *)string);
	new_string = _memory().calloc((size + 1), sizeof(char));
	index = size;
	while (index--)
		*new_string++ = *string++;
	new_string -= size;
	return (new_string);
}

char	*_string_trim(char *str)
{
	size_t	length;

	length = _string().length(str);
	while (_char().is_whitespace(str[length - 1]))
		--length;
	while (*str && _char().is_whitespace(*str))
	{
		++str;
		--length;
	}

	return (_string().dup_at(str, length));
}

void	_string_copy_at(char *dst, char *src, size_t size)
{
	size_t	index;

	index = size;
	while (index--)
		*dst++ = *src++;
	dst -= size;
}

void	_string_copy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}
