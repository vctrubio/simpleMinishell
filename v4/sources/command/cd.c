#include "../../includes/command.h"

char *_command_pre_cd(t_node_command *invoker, t_node_command *this)
{
	printf("command pre %s\n", this->name);
	if (this->next)
		this->next->pre_function(invoker, this->next);
	_command().delete(this);
	return (invoker->name);
}

void _command_cd(t_node_command *this)
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

	_command().delete(this);
}
