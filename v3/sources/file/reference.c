#include "../../includes/file.h"

int 	_file_create(int fd[2], char *path, int mode);
void	_file_close(int fd[2]);

t_file	_file(void)
{
	static t_file	file = {
		_file_create,
		_file_close
	};

	return (file);
}
