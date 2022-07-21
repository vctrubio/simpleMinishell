/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 17:27:24 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av, char **env)
{
	int		name;
	char	*line;
	char	**cmds;

	(void)av;
	if (ac != 1)
		return (0);
	while (*env)
		init_env(_string_new_hashmap(*env++));
	init_termios();
	while (1)
	{
		line = readline(ft_prompt());
		if (_string().length(line) == 0)
			continue ;
		else
			add_history(line);
		cmds = _string().split_char(line, ' ');
		while (*cmds)
		{
			name = _names(*cmds);
			init_command(*cmds, _pre_functions(name), _functions(name));
			++cmds;
		}
		execute_command();
		free_arrays(cmds);
		free(line);
		line = NULL;
	}
	return (0);
}


// int	main(int ac, char **av, char **env)
// {
// 	(void)ac;
// 	(void)av;
// 	(void)env;
// 	printf("%i\n", _char().is_whitespace('	'));
// 	// int		name;
// 	// char	*line;
// 	// char	**cmds;

// 	// if (ac != 1)
// 	// 	return (0);
// 	// (void)av;
// 	// while (*env)
// 	// 	init_env(new_hashmap(*env++));
// 	// while (1)
// 	// {
// 	// 	line = readline("$> ");
// 	// 	(cmds) = line_into_array(line); //this i HAVE 95% cmds ≠
// 	// 	while (*cmds)
// 	// 	{
// 	// 		name = _names(*cmds);
// 	// 		if (name >= 0)
// 	// 			init_command(*cmds, _functions(name)); //to-do     
// 	// 		else
// 	// 		{
// 	// 			///accessee8)
// 	// 		}
// 	// 		cmds++;
// 	// 	}
// 	// 	execute_command();
// 	// 	free(line);
// 	// }
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str;

// 	str = (char *) _memory().malloc(15);
// 	(_string().copy)(str, "tutorialspoint");
// 	printf("String = %s,  Address = %p\n", str, str);

// 	str = (char *) _memory().realloc(str, 25);
// 	printf("String = %s,  Address = %p\n", str, str);
// 	(_string().cat)(str, ".com");
// 	printf("String = %s,  Address = %p\n", str, str);

// 	_memory().free(str);
// 	return (0);
// }

// int	main(void)
// {
// 	char	*str = _string().itoa(-123);

// 	printf("%s\n", str);
// 	return (0);
// }

// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <string.h>

// // int	main(void)
// // {
// // 	char	*str;

// // 	str = (char *) _memory().malloc(15);
// // 	(_string().copy)(str, "tutorialspoint");
// // 	printf("String = %s,  Address = %p\n", str, str);

// // 	str = (char *) _memory().realloc(str, 25);
// // 	printf("String = %s,  Address = %p\n", str, str);
// // 	(_string().cat)(str, ".com");
// // 	printf("String = %s,  Address = %p\n", str, str);

// // 	str = "helloworld";
// // 	char *str2 = "enf of";
// // 	_string_cat(str, str2);
// // 	printf("%s\n", str);

	
// // 	_memory().free(str);
// // 	return (0);
// // }


// const char *str = "more.\n";

// void	file_create(char *name)
// {
// 	int	fd;

// 	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (fd == -1)
// 		return ;
// 	// write(fd, str, _string().length((char *)str));
// 	printf("Done Writing!\n");
// 	close(fd);
// }

// int	main(void)
// {
// 	int			fd;
// 	const char	*filename;

// 	filename = "innn.txt";
// 	file_create("file_create.txt");
// 	fd = open(filename, O_APPEND | O_CREAT | O_RDWR);
// 	// int fd = open(filename, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}

// 	write(fd, str, _string().length((char *)str));
// 	printf("Done Writing!\n");
// 	close(fd);
// 	exit(EXIT_SUCCESS);
// }

// int	main(void)
// {
// 	int	fd_1;
// 	int	saved_stdout;

// 	saved_stdout = dup(1);
// 	printf("Hello World1!\n");
// 	fd_1 = open("file_create.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	dup2(fd_1, 1);
// 	printf("Hello World2!\n");
// 	dup2(saved_stdout, 1);
// 	close(fd_1);
// 	printf("Hello World1!\n");
// 	return (0);
// }

// int main()
// {
//     // open() returns a file descriptor file_desc to a 
//     // the file "dup.txt" here"
  
//     int file_desc = open("file_create.txt", O_WRONLY | O_APPEND);
      
//     if(file_desc < 0)
//         printf("Error opening the file\n");
      
//     // dup() will create the copy of file_desc as the copy_desc
//     // then both can be used interchangeably.
  
//     int copy_desc = dup(file_desc);
          
//     // write() will write the given string into the file
//     // referred by the file descriptors
  
//     write(copy_desc,"This will be output to the file named dup.txt\n", 46);
          
//     write(file_desc,"This will also be output to the file named dup.txt\n", 51);
      
//     return 0;
// }






// redirecionamento





// void f(void)
// {
// 	printf("stdout in f()\n");
// }


// int	main(void)
// {
// 	int	fd;
// 	int	fd_2;

// 	printf("stdout, \n");
// 	fd = dup(1);
// 	fd_2 = open("file_create.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	dup2(fd_2, 1);
// 	f();
// 	dup2(fd, 1);
// 	printf("stdout again\n");
// 	return (0);
// }


