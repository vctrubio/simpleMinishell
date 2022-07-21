#include "../include/minishell.h"

char	*get_usr(void)
{
	char	*usr;
	char	tmp[202];
	int		i;
	int		j;

	getcwd(tmp, sizeof(tmp));
	usr = malloc(sizeof(char) * ft_strlen(tmp));
	i = 7;
	j = 0;
	while (tmp[i] != '/')
		usr[j++] = tmp[i++];
	usr = ft_strjoin(usr, "\033[0;31m@\033[0;33m42\033[0;32mLisboa\033[0m");
	return (usr);
}

char	*ft_prompt(void)
{
	char	*str;
	char	prompt[255];
	int		status; //statuc of last command, if SUCCESS green, if failer RED, if -1 BLACK

	status = get_shell()->ec;
	str = getcwd(prompt, sizeof(prompt));
	while (*str)
		str++;
	while (*str != '/')
		str--;
	str++;
	return (ft_strjoin(str, "$> "));
}
