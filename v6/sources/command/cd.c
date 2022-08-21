/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:44:15 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/18 08:05:55 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

#include <sys/types.h>
#include <dirent.h>

char	*_command_pre_cd(t_node_command *invoker, t_node_command *this)
{
	if (this->next)
		this->next->builting->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void	_command_cd(t_node_command *this)
{
// 	printf("command %s\n", this->name);
// 	if (this->next)
// 		this->next->pre_function(this, this->next);

// #include <stdio.h>
// #include <stdlib.h>
// #include <dirent.h>
// #include <errno.h>

// 		DIR *dp;
// 		struct dirent *dirp;


// 		dp = opendir();

// 		while ((dirp = readdir(dp)) != NULL)
// 			printf("%s\n", dirp->d_name);

// 		closedir(dp);
// 		exit(EXIT_SUCCESS);
	int ch=chdir(this->next->name);
    if(ch<0)
    printf("chdir change of directory not successful\n");
    else
    printf("chdir change of directory successful\n");
	_command().delete(this->next);
	_command().delete(this);
}
