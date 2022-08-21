/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:43:36 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:39 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

t_pre_function _command_pre_function(int index)
{
	static t_pre_function functions[8] = {
		_command_pre_echo,
		_command_pre_cd,
		_command_pre_greater_than,
		_command_pre_more_greater_than,
		_command_pre_export,
		_command_pre_unset,
		_command_pre_env,
		_command_pre_system};

	if (index < 0)
		return (NULL);
	return (functions[index]);
}
