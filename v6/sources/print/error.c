/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:39:20 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:39:21 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/print.h"

int print_string(char *string)
{
	int length;

	length = _string().length(string);
	write(1, string, length);
	return (length);
}
