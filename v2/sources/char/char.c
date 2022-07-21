/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:56:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/03 10:06:26 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

t_char	_char(void)
{
	static t_char	_char = {
		_to_lower,
		_to_upper,
		_is_alpha,
		_is_lowercase,
		_is_uppercase,
		_is_whitespace
	};

	return (_char);
}

