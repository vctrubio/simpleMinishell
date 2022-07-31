#include "../../includes/command.h"

char *_command_token(char **name, t_node_command *command);

// char *ft_strjoin(char *s1, char *s2)
// {
// 	char *result = _memory().malloc(_string().length(s1) + _string().length(s2) + 1); // +1 for the null-terminator
// 	// in real code you would check for errors in malloc here
// 	_string().copy(result, s1);
// 	_string().copy(result + _string().length(s1), s2);
// 	return result;
// }
void *ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if ((n == 0) || (dst == src))
		return (dst);
	while (i < n)
	{
		*(char *)dst++ = *(char *)src++;
		i++;
	}
	return (dst - n);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *ptr;
	int s1_len;
	int s2_len;
	int t;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = _string().length(s1);
	s2_len = _string().length(s2);
	t = s1_len + s2_len;
	ptr = (char *)_memory().malloc(sizeof(char) * (t + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	ptr[t] = '\0';
	return (ptr);
}

char *_command_pre_system(t_node_command *invoker, t_node_command *this)
{
	char *name;

	if (!_command_token(&name, this->next))
	{
		name = ft_strjoin(this->name, " ");
		name = ft_strjoin(name, this->next->pre_function(invoker, this->next));
	}
	else
		name = _string().dup(this->name);
	_command().delete(this);
	return (name);
}

char *get_cmd(char **paths, char *cmd)
{
	int i;
	char *inter;
	char *cmd_path;

	i = 0;
	while (paths[i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmd);
		_memory().free(inter);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		_memory().free(cmd_path);
		i++;
	}
	return (0);
}

void terminate(char *m)
{
	// if (errno == 0)
	// 	write(2, "Error\n", 6);
	// else
	perror(m);
	exit(EXIT_FAILURE);
}

void _command_system(t_node_command *this)
{
	char *name;
	char **args;
	char **paths;
	char *path;
	int test;
	pid_t c_pid;

	test = 0;
	if (this->next)
	{
		name = ft_strjoin(this->name, " ");
		name = ft_strjoin(name, this->next->pre_function(this, this->next));
	}
	else
		name = ft_strjoin(this->name, "");
	if (this)
	{
		c_pid = fork();
		if (c_pid < 0)
			terminate("fork");
		if (c_pid == 0)
		{
			args = _string().split_char(name, ' ');
			path = _env().get("PATH")->value;
			paths = _string().split_char(path, ':');
			while (args[test])
				test++;
			args[test] = NULL;
			if (execve(get_cmd(paths, this->name), args, NULL))
				printf("Error\n");
		}
		wait(NULL);
	}
	_command().delete(this);
}
