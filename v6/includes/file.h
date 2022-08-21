/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:45:04 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 14:16:01 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_file	t_file;

struct s_file
{
	int		(*create)(int fd[2], char *path, int mode);
	void	(*close)(int fd[2]);
};

t_file	_file(void);

#endif // FILE_H
