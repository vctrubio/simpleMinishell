#include "../../includes/char.h"

int _to_lower(int c)
{
	if (_char().is_uppercase(c))
		return (c + 32);
	return (c);
}
