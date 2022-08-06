#include "../../includes/string.h"

char *_string_dup(const char *string)
{
	char *new_string;
	int len;

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

	if (size > _string().length((char *)string))
		size = _string().length((char *)string);
	new_string = _memory().calloc((size + 1), sizeof(char));
	index = size;
	while (index--)
		*new_string++ = *string++;
	new_string -= size;
	return (new_string);
}