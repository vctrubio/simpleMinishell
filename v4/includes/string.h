#ifndef STRING_H
#define STRING_H

#include <sys/types.h>
#include <stdio.h>

#include "memory.h"

typedef struct s_string t_string;

struct s_string
{
	char *(*read_line)(char *string);
	void (*copy)(char *dst, char *src);
	char *(*dup)(const char *string);
	char *(*dup_at)(const char *string, size_t size);
	int (*equals)(char *str1, char *str2);
	int (*beginning_equals)(char *str1, char *str2);
	int (*is_quote)(char c);
	char *(*itoa)(int n);
	size_t (*length)(char *string);
	char **(*split_char)(char *string, char separator);
	char **(*split_string)(char *string, char *separator);
};

t_string _string(void);

char *_string_read_line(char *string);
void _string_copy(char *dst, char *src);
char *_string_dup(const char *string);
char *_string_dup_at(const char *string, size_t size);
int _string_equals(char *str1, char *str2);
int _string_beginning_equals(char *str1, char *str2);
int _string_is_quote(char c);
char *_string_itoa(int n);
size_t _string_length(char *string);
char **_string_split_char(char *string, char separator);
char **_string_split_string(char *string, char *separator);

#endif // DOBLY_LINKED_LIST_H