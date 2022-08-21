/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:40:39 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:40:40 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parse.h"

void dollar_for_money(char **cpy, char **str) // ptr to ptr
{
	char *tmp;
	int i;
	int j;

	i = _string().length(*cpy);
	j = 0;
	(*str)++;
	tmp = NULL;
	if (**str == '?')
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
