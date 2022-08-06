#include "../../includes/parse.h"

void	_stradd(char **str, char *add)
{
  int   i;

  if (*str == NULL)
    return ;
  i = 0;
  while ((*str)[i])
    i++;
  (*str) = _memory().realloc((*str), _string().length(*str) + _string().length(add) + 1);
  while (*add)
  {
    (*str)[i++] = *add;
    add++;
  }
  (*str)[i] = 0;
}

int		_strcount_char(char *str, char l)
{
	int i;

	i = 0;
	if (!str || !l)
		return (0);
	while (*str)
	{
		if (*str == l)
			i++;
		str++;
	}
  return (i);
}

int		r_size(char *s)
{
	unsigned int len;

	len = 1;
	while ((*s)++)
	{
		++len;
		if (*s == '>')
			break;
		++s;
		
	}
	return (len);
}
