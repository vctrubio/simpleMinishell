/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:40:47 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:07 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void	free_arrays(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		_memory().free(arr[i]);
		arr[i++] = NULL;
	}
	_memory().free(arr);
	arr = NULL;
}
