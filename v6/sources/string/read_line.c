/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:36:19 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:36:20 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string.h"

char *_string_read_line(char *string)
{
	char	*line;
	int 	pipe_fd[2];
	int 	length;
	static char	buffer[4096] = {0};

	// pipe_1 = 0;
	pipe(&pipe_fd[0]);
	close(pipe_fd[0]);
	write(1, string, _string().length(string));
	pipe_fd[1] = dup(1);
	dup2(pipe_fd[0], 1);
	while (1)
	{
		length = read(1, buffer, 4096);
		if (buffer[length - 1] == '\n')
		{
			buffer[length - 1] = 0;
			break;
		}
		//write(1, buffer, _string().length(buffer));
	}
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	// close(pipe_1);
	line = _string().dup(buffer);
	return (line);
}
