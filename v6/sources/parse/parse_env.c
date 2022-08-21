/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:41:13 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:41:14 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"
#include "../../includes/char.h"

void update_string_env(t_vars *vars)
{
	vars->new = _string().replace(vars->new, vars->start, vars->index - 1, vars->temp);
	vars->index = vars->start + _string().length(vars->temp) + vars->correction;
	_memory().free(vars->temp);
	vars->start = -1;
	vars->temp = NULL;
}

void init_vars(t_vars *vars, char *string)
{
	vars->new = string;
	vars->env = NULL;
	vars->temp = NULL;
	vars->index = 0;
	vars->start = -1;
	vars->correction = 0;
}

void set_temp(t_vars *vars, char c)
{
	char *temp;
	t_node_env *env;

	if (vars->start < 0)
	{
		vars->start = vars->index++;
		return;
	}
	if (c == '?')
		temp = _string().itoa(_shell()->ec);
	temp = _string().dup_at(vars->new + vars->start, vars->index - vars->start);
	env = _env().get(temp + 1);
	_memory().free(temp);
	if (env)
		vars->temp = _string().dup(env->value);
	else
		vars->temp = NULL;
	vars->correction = (c == '.' || c == '?');
}

char *_parce_string_env(char *string)
{
	t_vars vars;

	if (!string)
		return (NULL);
	init_vars(&vars, _string().dup(string));
	while (vars.new[vars.index])
	{
		if (vars.new[vars.index] == '$')
			set_temp(&vars, ' ');
		else if (vars.new[vars.index] == '?')
			set_temp(&vars, '?');
		else if (vars.new[vars.index] == '.' && vars.start > -1)
			set_temp(&vars, '.');
		if (!vars.temp)
			vars.index++;
		else
			update_string_env(&vars);
	}
	if (vars.start > -1)
	{
		set_temp(&vars, ' ');
		update_string_env(&vars);
	}
	return (vars.new);
}
