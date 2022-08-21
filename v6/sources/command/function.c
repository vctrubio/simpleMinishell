/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:55 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:56 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_function _command_function(int index)
{
	static t_function functions[8] = {
		_command_echo,
		_command_cd,
		_command_greater_than,
		_command_more_greater_than,
		_command_export,
		_command_unset,
		_command_env,
		_command_system};

	if (index < 0)
		return (NULL);
	return (functions[index]);
}
