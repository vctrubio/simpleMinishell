/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:44:31 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

t_char _char(void)
{
	static t_char _char = {
		_is_alpha,
		_is_lowercase,
		_is_uppercase,
		_is_whitespace,
		_is_special_parse,
		_to_lower,
		_to_upper};

	return (_char);
}
