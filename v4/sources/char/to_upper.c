#include "../../includes/char.h"

int _to_upper(int c)
{
	if (_char().is_lowercase(c))
		return (c - 32);
	return (c);
}
