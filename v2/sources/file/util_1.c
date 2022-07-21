/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 09:13:32 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/04 10:49:43 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/file.h"

int	file_create(char *name)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	file_write_close(int fd, char *str)
{
	write(fd, str, _string().length(str));
	close(fd);
}

void	file_write_by_fd(int fd)
{
	write(fd, str, _string().length(str));
}

void	file_overwrite(int fd, char *str)
{
	int	fd;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write(fd, str, _string().length((char *)str));
	printf("Done Writing!\n");
	close(fd);
}
