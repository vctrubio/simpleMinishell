/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:27 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:28 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/env.h"

void	_env_update(char*** old_env, char** new_env)
{
	while (*old_env && **old_env)
	{
		_memory().free(**old_env);
		(*old_env)++;
	}
	_memory().free(*old_env);
	*old_env = new_env;
}
