/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:01:48 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 12:35:00 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

int	_to_upper(int c)
{
	if (_char().is_lowercase(c))
		return (c - 32);
	return (c);
}
