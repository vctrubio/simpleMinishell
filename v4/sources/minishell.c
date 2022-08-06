#include "../includes/minishell.h"

t_shell *_shell(void)
{
    static t_shell shell;

    return (&shell);
}

void do_with_ac(int ac, char **av)
{
    char *line;
    char **cmds;

    for (int i = 1; i < ac; i++)
    {
        line = av[i];
        if (_string().length(line) > 0)
        {
            if (_string().equals(line, "exit"))
                break;
            add_history(line);
            cmds = buffer_into_array(line);
            while (_string().length(*cmds) > 0)
            {
                _command().create(*(cmds++));
            }
        }
        _command().execute();
        _memory().free(cmds);
        cmds = 0;
    }
    exit(1);
}

int main(int ac, char **av, char **env)
{
    char *line;
    char **cmds;

    // echo $USER = *joaoribeiro*
    (void)av;
    if (ac != 1)
        return (0);
    _shell()->home = getenv("HOME");
    _shell()->pwd = getenv("PWD");
    while (*env)
        _env().create(_string().dup(*(env++)));
    _shell()->env = _env().to_double_pointer();
    while (1)
    {
        line = readline("$> ");
        if (_string().length(line) == 0)
            continue;
        else
            add_history(line);
        cmds = buffer_into_array(line);
        // cmds = _string().split_char(line, ' ');
        // print_arrays(cmds);

        // g USER => $ USER
        
        while (*cmds)
            _command().create(*(cmds++));
        _command().execute();
        free_arrays(cmds);
        free(line);
        line = NULL;
    }
    return (0);
}
