#include "../../includes/parse.h"

// echo $HOME
// echo $?
// echo $?$hi 1
// echo $?$HOME 1/Users/joao

void dollar_for_money(char **cpy, char **str) // ptr to ptr
{
	//$ str++
	// USER
	// HOME
	//?
	char *tmp;
	int i;
	int j;

	i = _string().length(*cpy);
	j = 0;
	(*str)++;
	tmp = NULL;
	if (**str == '?') // EXIT CODE - echo hi$? =hi0
	{
		(*str)++;
		tmp = _string().itoa(_shell()->ec);
		while (tmp[j])
			(*cpy)[i++] = tmp[j++];
	}
	else
	{

		while ((*str)[j] != '$' && !_char().is_whitespace((*str)[j]) && !_string().is_quote((*str)[j]) && (*str)[j])
			j++;
		tmp = _string().dup_at(*str, j);
		// tmp = USER
		*str += j;
		tmp = _env().get(*str)->value;
		// ≠ (null)
		//$PWD$PWD PWD x2
		//$PWD hi

		// tmp = joaome
		// output = tmp
		//  command name xxx$xxxxxxx   (key_size + xxx)
		// echo hi$PWD = hi42/joao/circle-03
		//  ls|echo
	}
	_stradd(cpy, tmp);
	free(tmp);
	tmp = 0;
}

void ft_squote(char **cpy, char **str) // single quote
{
	int i;

	i = _string().length(*cpy);
	(*str)++;
	while (**str != '\'' && **str)
		(*cpy)[i++] = *(*str)++;
}

void ft_db_quote(char **cpy, char **str) // db quote
{
	int i;

	i = 0;
	(*str)++;
	while (**str != '"' && **str)
	{
		i = _string().length(*cpy);
		if (**str == '$' && (**str + 1 != '\'' || **str + 1 != '"'))
			dollar_for_money(cpy, str);
		else
			(*cpy)[i] = *(*str)++;
	}
}

char *parse_clean(char *str)
{
	int i;
	char *cpy;

	// we dont know lenght of copy - "hi""" = len is 2
	// we dont know lenght of copy - "hi"""$PWD = len is 12 + 2
	// we dont know lenght of copy - "hi"""$MYPWD = len is 120 + 2
	printf("intro to parse_clean of (%s)\n", str);
	i = 0;

	// cpy = _memory().malloc(sizeof(_string().length(str)));
	cpy = calloc(100, 1);
	while (*str)
	{
		i = _string().length(cpy);
		if (*str == '\'')
			ft_squote(&cpy, &str);
		else if (*str == '"')
			ft_db_quote(&cpy, &str);
		else if (*str == '$')
			dollar_for_money(&cpy, &str);
		else
		{
			cpy[i] = *str;
			str++;
		}
	}
	cpy[_string().length(cpy) + 1] = 0;
	printf("returning cpy: %s: \n", cpy);
	return (cpy);
}

/* to watch out for
* echo / $PWD'out' / $PWD$USR / $PWDout / $'this'
* echo "$PWD" / '$PWD' / "$'PWD'"
'$HOME' -> RETURN $HOME - but should return -1
*/
