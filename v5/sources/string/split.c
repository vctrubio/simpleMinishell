#include "../../includes/string.h"

static char **_string_char(char *string, char separator, char **list, int index)
{
	int length;
	char *new_string;

	while (string && *string == separator)
		string++;
	length = 0;
	while (string[length] && string[length] != separator)
		length++;
	new_string = _memory().calloc(sizeof(char), (length + 1));
	length = 0;
	while (string && *string && *string != separator)
		new_string[length++] = *string++;
	while (string && *string == separator)
		string++;
	if (string && *string)
		list = _string_char(string, separator, list, index + 1);
	else
		list = _memory().calloc(sizeof(char *), (index + 2));
	list[index] = new_string;
	return (list);
}

static char **_string_string(char *string, char *separator,
							 char **list, int index)
{
	int _index;
	char *new_string;

	while (string && _string().beginning_equals(string, separator) > 0)
		string += _string().length(separator);
	_index = 0;
	while (!_string().beginning_equals(string + _index, separator) &&
			string[_index])
		_index++;
	new_string = _memory().malloc(sizeof(char) * (_index + 1));
	_index = 0;
	while (string && *string && !_string().beginning_equals(string, separator))
		new_string[_index++] = *string++;
	if (string && *string)
		list = _string_string(string, separator, list, index + 1);
	else
		list = _memory().malloc(sizeof(char *) * (index + 1));
	list[index] = new_string;
	return (list);
}

char **_string_split_char(char *string, char separator)
{
	return (_string_char(string, separator, NULL, 0));
}

char **_string_split_string(char *string, char *separator)
{
	return (_string_string(string, separator, NULL, 0));
}