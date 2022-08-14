#include "../../includes/string.h"

char *_string_dup(const char *string)
{
	char *new_string;
	int len;

	if (!string)
		return (NULL);
	len = _string().length((char *)string);
	new_string = _memory().calloc((len + 1), sizeof(char));
	if (!new_string)
		return (NULL);
	while (*string)
		*new_string++ = *string++;
	new_string -= len;
	return (new_string);
}

char *_string_dup_at(const char *string, size_t size)
{
	size_t index;
	char *new_string;

	if (!string)
		return (NULL);
	if (size > _string().length((char *)string))
		size = _string().length((char *)string);
	new_string = _memory().calloc((size + 1), sizeof(char));
	index = -1;
	while (++index < size)
		new_string[index] = string[index];
	return (new_string);
}