/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:10 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:18 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/file.h"

int _file_create(int fd[2], char *path, int mode)
{
	fd[0] = open(path, O_CREAT | O_WRONLY | mode, 0644);
	if (fd[0] > 0)
	{
		fd[1] = dup(1);
		dup2(fd[0], 1);
	}
	else
		printf("Minishell: %s: Permission denied\n", path);
	return (!(fd[0] > 2));
}
