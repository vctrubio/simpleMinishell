/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:13:37 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 14:32:37 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

void	_string_cat(char *string, char *to_cat)
{
	while (*string)
		string++;
	while (*to_cat)
		*string++ = *to_cat++;
	*string = '\0';
}
