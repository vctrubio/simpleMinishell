#include "../../includes/char.h"

int _is_alpha(int c)
{
	return (_is_uppercase(c) || _is_lowercase(c));
}
