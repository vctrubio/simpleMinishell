#include "../../includes/print.h"

int print_string(char *string)
{
	int length;

	length = _string().length(string);
	write(1, string, length);
	return (length);
}
