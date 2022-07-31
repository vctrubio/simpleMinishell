#include "../../includes/string.h"

int _string_is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (1);
	return (0);
}