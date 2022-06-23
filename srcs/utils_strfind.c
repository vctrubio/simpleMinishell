#include "../include/minishell.h"

char	*ft_strldupimp(char *str, int i, int j);
char  *ft_strldup(char *str, int l);
char  *ft_strfdup(char *str, int f);
int		r_size(char *s);

int		r_size(char *s)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			++s;
		else
		{
			++len;
			while (*s && !ft_isspace(*s))
				++s;
		}
	}
	return (len);
}

char  *ft_strldup(char *str, int l)
{
  char  *dest;
  int   i;

  dest = malloc(sizeof(char) * l + 1);
  if (!dest)
    perror("ft_strldup:MALLOC ALLOCATION ERROR");
  i = 0;
  while (i < l)
  {
    dest[i] = str[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

char  *ft_strfdup(char *str, int f)
{
  char  *out;
  char  *str2;
  int   i;

  str2 = str;
  i = 0;
  while(*str != f)
  {
    if (*str == 0)
      break;
    str++;
    i++;
  }
  out = ft_strldup(str2, i);
  return (out);
}

char	*ft_strldupimp(char *str, int i, int j)
{
	char	*dest;
	int		k;
	
	if (i == j)
		return (0);
	dest = malloc(sizeof(char) * (j - i) + 1);
	if (dest == NULL)
		return (0);
	k = 0;
	while(i <= j)
	{
		dest[k++] = str[i++];
	}
	dest[k] = 0;
	return (dest);
}