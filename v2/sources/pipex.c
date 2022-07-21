/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:16:23 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/05 13:19:42 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- > 1 && *s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strlen(char *string)
{
	if (string && *string)
		return (1 + ft_strlen(++string));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*join_start;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	join_start = join;
	while (*s1)
	{
		*join = *s1;
		join++;
		s1++;
	}
	while (*s2)
	{
		*join = *s2;
		join++;
		s2++;
	}
	*join = '\0';
	return (join_start);
}

static char	**_char(char *string, char separator, char **list, int index)
{
	int		length;
	char	*new_string;

	while (string && *string == separator)
		string++;
	length = 0;
	while (string[length] != separator && string[length])
		length++;
	new_string = malloc(sizeof(char) * (length + 1));
	length = 0;
	while (string && *string && *string != separator)
		new_string[length++] = *string++;
	if (string && *string)
		list = _char(string, separator, list, index +1);
	else
		list = malloc(sizeof(char *) * (index + 1));
	list[index] = new_string;
	return (list);
}

char	**ft_split(char *string, char separator)
{
	return (_char(string, separator, NULL, 0));
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	int		i;
	char	*inter;
	char	*cmd_path;

	i = 0;
	while (paths[i])
	{
		inter = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(inter, cmd);
		free(inter);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	print_arrays(char **a)
{
  int i;

  i = 0;
	while(a[i])
	{
	  printf("%s\n", a[i++]);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**paths;

	paths = ft_split(find_path(env), ':');
	printf("%s\n", get_cmd(paths,  argv[1]));
	print_arrays(argv + 1);
	execve(get_cmd(paths, argv[1]), argv + 1, NULL);
	return (0);
}
