#ifndef CHAR_H
# define CHAR_H

typedef struct s_char
{
	int		(*is_alpha)(int c);
	int		(*is_lowercase)(int c);
	int		(*is_uppercase)(int c);
	int		(*is_whitespace)(int c);
	int		(*to_lower)(int c);
	int		(*to_upper)(int c);
}	t_char;

t_char	_char(void);

int		_is_alpha(int c);
int		_is_lowercase(int c);
int		_is_uppercase(int c);
int		_is_whitespace(int c);
int		_to_lower(int c);
int		_to_upper(int c);


#endif // CHAR_H
