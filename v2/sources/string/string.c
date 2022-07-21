/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:10:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/03 11:48:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

t_string	_string(void)
{
	static t_string	_string = {
		_string_length,
		_string_equals,
		_string_contains,
		_string_index_of,
		_string_beginning_equals,
		_string_copy,
		_string_cat,
		_string_copy_at,
		_string_itoa,
		_string_dup,
		_string_dup_at,
		_string_split_char,
		_string_split_string,
		_string_isquote
	};

	return (_string);
}
