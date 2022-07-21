#include "../includes/prompt.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;
	int		t;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = _string().length(s1);
	s2_len = _string().length(s2);
	t = s1_len + s2_len;
	ptr = (char *)malloc(sizeof(char) * (t + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	ptr[t] = '\0';
	return (ptr);
}

char	*ft_prompt(void)
{
	char	*str;
	char	prompt[255];

	str = getcwd(prompt, sizeof(prompt));
	while (*str)
		str++;
	while (*str != '/')
		str--;
	str++;
	return (ft_strjoin(str, "$> "));
}
