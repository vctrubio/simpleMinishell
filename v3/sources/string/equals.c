#include "../../includes/string.h"

int _string_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str1 && !*str2);
}

int _string_beginning_equals(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
		if (*(str1++) != *(str2++))
			return (0);
	return (!*str2);
}