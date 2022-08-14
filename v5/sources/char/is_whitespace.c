#include "../../includes/char.h"

int _is_whitespace(int c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}
