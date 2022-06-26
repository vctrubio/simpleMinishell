#include "../include/minishell.h"
char		**ft_strsplit(char const *str, char c);
int			count_words(char *str, char c);
void  		ft_stradd(char **str, char *add);

int	count_words(char *str, char c)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str == 0)
			return (i);
		while (*str && *str != c )
			str++;
		if (*str == 0)
			return (i + 1);
		i++;
	}
	return (i);
}


char		**ft_strsplit(char const *str, char c)
{
	char	**split;
	int		i;
	int		i2;
	int		cnt;

	i = 0;
	i2 = 0;
	cnt = 0;
	if (!(split = (char **)malloc(sizeof(char *) * (count_words((char *)str, c) +1))))
		return (0);
	while (cnt < count_words((char *)str, c) && count_words((char *)str, c) > 0)
	{
		while (str[i] == c && str[i])
			i++;
		i2 = i;
		while (str[i] != c && str[i])
			i++;
		split[cnt++] = ft_substr((char *)str, i2, i -i2);
	}
	split[cnt] = 0;
	return (split);
}

void  ft_stradd(char **str, char *add)
{
  int   i;

  if (*str == NULL)
    return ;
  i = 0;
  while ((*str)[i])
    i++;
  (*str) = realloc((*str), ft_strlen(*str) + ft_strlen(add) + 1);
  while (*add)
  {
    (*str)[i++] = *add;
    add++;
  }
  (*str)[i] = 0;
}
