#include "../../includes/string.h"

t_string _string(void)
{
    static t_string _string = {
        _string_read_line,
        _string_copy,
        _string_dup,
        _string_dup_at,
        _string_equals,
        _string_beginning_equals,
        _string_is_quote,
        _string_itoa,
        _string_length,
        _string_split_char,
        _string_split_string
    };

    return (_string);
}
