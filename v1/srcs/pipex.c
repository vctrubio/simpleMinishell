#include "../include/minishell.h"
char	*find_cmd_path(char *str);
int		ft_pipe(char *cmd, char **argv);

// fd 0 = STDIN_FILENO
// fd 1 = STDOUT_FILENO
// fd 2 = STDERR_FILENO

char	*find_cmd_path(char *str)
{
	t_ll	*env;
	char	**cmd_split;

	env = get_shell()->env;
	while (!ft_strexact(env->name, "PATH"))
		env = env->next;
	if (!env)
		return (0);
	// printf("cmd_path: %s\n", env->content);
	cmd_split = ft_strsplit(env->content, ':');
	while (*cmd_split)
	{
		ft_stradd(&(*cmd_split), "/");
		ft_stradd(&(*cmd_split), str);
		if (access(*cmd_split, F_OK) == 0)
		{
			return (*cmd_split);
			printf("we have cmd_split: %s :\n", *cmd_split);
		}
		cmd_split++;
	}
	return (0);
}

int ft_pipe(char *cmd, char **argv)
{
	// i = 0;
	// while (argv[++i])
	// 	printf("-%s\n", argv[i]);
	printf("ft_pipe: %s\n", cmd);
	char	*cmd_path;
	int		fd[2];
	pid_t		pid;

	// char	**tmp_array;
	// int		i = 0;
	// tmp_array[i++] = cmd;
	// while (*argv)
	// {
	// 	tmp_array[i++] = *argv;
	// 	argv++;
	// }
	// tmp_array[i] = 0;

	// pipe(fd);
	// pid = fork();
	// if (pid == 0 && ())

	cmd_path = find_cmd_path(cmd);
	pid = fork();
	if (pid == 0)
		execve(cmd_path, argv, get_shell()->envp);
	else
	{
		printf("parent pid.\n");
	 wait(&pid);
	}

	close(fd[0]);
	close(fd[1]);
	return (0);
}
