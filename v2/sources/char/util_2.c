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

/**
 * @brief 
 * 
 * @param c letter to be converted to lowercase.
 * @return returns lowercase equivalent to c, if 
 * such value exists, else c remains unchanged. The 
 * value is returned as an int value that can be 
 * implicitly casted to char.
 */
int	_to_lower(int c)
{
	if (_char().is_uppercase(c))
		return (c + 32);
	return (c);
}

/**
 * @brief 
 * 
 * @param c letter to be converted to uppercase.
 * @return returns uppercase equivalent to c, if 
 * such value exists, else c remains unchanged. 
 * The value is returned as an int value that can 
 * be implicitly casted to char.
 */
int	_to_upper(int c)
{
	if (_char().is_lowercase(c))
		return (c - 32);
	return (c);
}
