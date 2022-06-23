#include "../include/minishell.h"
bool  ft_strlook_char(char *str, char l); //str look for one character
bool  ft_strlook(char *str, char *look); //str look for set of character
bool	ft_strexact(char *s1, char *s2); //if its exactly the same
bool  ft_strexact_abs(char *s1, char *s2); //if its exactly the same- but alpha
bool  ft_isspace(char c);
bool  ft_strlook_char(char *str, char l)
{
  int i;

  if (!str || !l)
    return (false);
  while (*str)
  {
      if (*str == l)
        return (true);
    str++;
  }
  return (false);
}

bool  ft_strlook(char *str, char *look)
{
  int i;

  if (!str || !look)
    return (false);
  while (*str)
  {
    i = 0;
    while (look[i])
    {
      if (*str == look[i])
        return (true);
      i++;
    }
    str++;
  }
  return (false);
}

bool	ft_strexact(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (*s1)
	{
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

bool	ft_strexact_abs(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (*s1)
	{
    *s1 = ft_tolower(*s1);
    *s2 = ft_tolower(*s2);
		if (*s1 != *s2)
			return (false);
		s1++;
		s2++;
	}
	return (true);
}

bool	ft_isspace(char c)
{
	if (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
