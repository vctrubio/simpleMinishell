/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:57:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 12:36:05 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

typedef struct s_char
{
	int		(*to_lower)(int c);
	int		(*to_upper)(int c);
	int		(*is_alpha)(int c);
	int		(*is_lowercase)(int c);
	int		(*is_uppercase)(int c);
	int		(*is_whitespace)(int c);
}	t_char;

t_char	_char(void);

int		_to_lower(int c);
int		_to_upper(int c);
int		_is_alpha(int c);
int		_is_lowercase(int c);
int		_is_uppercase(int c);
int		_is_whitespace(int c);


#endif // CHAR_H
