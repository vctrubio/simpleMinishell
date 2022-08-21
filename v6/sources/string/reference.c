/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:36:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/16 08:41:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

t_string	_string(void)
{
	static t_string	_string = {
		_string_index_of,
		_string_contains,
		_string_read_line,
		_string_copy,
		_string_dup,
		_string_dup_at,
		_string_equals,
		_string_beginning_equals,
		_string_is_quote,
		_string_itoa,
		_string_length,
		_string_split_char,
		_string_split_string,
		_string_replace};

	return (_string);
}
