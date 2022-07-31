#include "../../includes/string.h"

void _string_copy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}