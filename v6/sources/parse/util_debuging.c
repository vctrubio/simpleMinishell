/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_debuging.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:40:43 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:40:44 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void print_arrays(char **a)
{
	int i;

	i = 0;
	while (a[i])
	{
		printf("%s-\n", a[i++]);
	}
}
