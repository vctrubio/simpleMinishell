/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:01:48 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/02 09:57:52 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

int	_is_lowercase(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	_is_uppercase(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	_is_alpha(int c)
{
	return (_is_uppercase(c) || _is_lowercase(c));
}

int	_is_whitespace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
