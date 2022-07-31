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

t_file		_file(void);

#endif // FILE_H
