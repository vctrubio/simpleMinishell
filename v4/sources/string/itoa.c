#include "../../includes/string.h"

static int convert_str(int index, int number, char str[11])
{
	if (number >= 10 || number <= -10)
		index = convert_str(index, number / 10, str);
	number *= (number > 0) - (number < 0);
	str[index] = (number % 10) + 48;
	str[++index] = 0;
	return (index);
}

char *_string_itoa(int n)
{
	int index;
	char ptr[11];
	char *str;

	*ptr = '-';
	index = (n < 0);
	index = convert_str(index, n, ptr);
	str = _memory().calloc((index + 1), sizeof(char));
	(_string().copy)(str, ptr);
	return (str);
}