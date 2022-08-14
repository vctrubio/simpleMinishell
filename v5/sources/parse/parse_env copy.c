// #include "../../includes/parse.h"
// #include "../../includes/char.h"

// char *_parce_string_env(char *string)
// {
// 	int index;
// 	int start;
// 	char *new_string;
// 	char *temp;

// 	index = 0;
// 	start = -1;
// 	temp = NULL;
// 	if (!string)
// 		return (0);
// 	new_string = _string().dup(string);
// 	while (new_string[index])
// 	{
// 		if (new_string[index] == '$')
// 		{
// 			if (start < 0)
// 				start = index++;
// 			else
// 			{
// 				if (new_string[index - 1] == '$')
// 				{
// 					temp = _string().itoa(getpid());
// 					new_string = _string().replace(new_string, start, index, temp);
// 					index = start + _string().length(temp);
// 					// index = update_str_with_env(&new_string, &start, index, temp);
// 				}
// 				else
// 				{
// 					temp = _string().dup_at(new_string + start, index - start);
// 					new_string = _string().replace(new_string, start, index - 1, _env().get(temp + 1)->value);
// 					index = start + _string().length(_env().get(temp + 1)->value);
// 					// index = update_str_with_env(&new_string, &start, index, _env().get(temp + 1)->value);
// 				}
// 				start = -1;
// 				_memory().free(temp);
// 				temp = NULL;
// 			}
// 		}
// 		else if (new_string[index] == '.' && start > -1)
// 		{
// 			temp = _string().dup_at(new_string + start, index - start);
// 			new_string = _string().replace(new_string, start, index - 1, _env().get(temp + 1)->value);
// 			index = start + _string().length(_env().get(temp + 1)->value) + 1;
// 			// index = update_str_with_env(&new_string, &start, index, _env().get(temp + 1)->value) + 1;
// 			start = -1;
// 			_memory().free(temp);
// 			temp = NULL;
// 		}
// 		else
// 			index++;
// 		temp = NULL;
// 	}
// 	if (start > -1)
// 	{
// 		temp = _string().dup(new_string + start);
// 		new_string = _string().replace(new_string, start, index - 1, _env().get(temp + 1)->value);
// 		index = start + _string().length(_env().get(temp + 1)->value);
// 		// index = update_str_with_env(&new_string, &start, index, _env().get(temp + 1)->value);
// 		_memory().free(temp);
// 	}
// 	temp = NULL;
// 	return (new_string);
// }
