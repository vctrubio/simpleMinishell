#include "../includes/file.h"

void _file_close(int fd[2])
{
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
}
