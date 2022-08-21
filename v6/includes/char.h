/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:45:12 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:55:49 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

typedef struct s_char	t_char;
struct s_char
{
	int	(*is_alpha)(int c);
	int	(*is_lowercase)(int c);
	int	(*is_uppercase)(int c);
	int	(*is_whitespace)(int c);
	int	(*is_special_parse)(int c);
	int	(*to_lower)(int c);
	int	(*to_upper)(int c);
};

t_char	_char(void);

int		_is_alpha(int c);
int		_is_lowercase(int c);
int		_is_uppercase(int c);
int		_is_whitespace(int c);
int		_is_special_parse(int c);
int		_to_lower(int c);
int		_to_upper(int c);

#endif // CHAR_H
