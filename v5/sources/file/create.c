#include "../../includes/file.h"

// O_MODE == O_TRUNC: truncate the file to 0 bytes
// O_MODE == O_APPEND: append to the end of the file

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
