#include "../includes/minishell.h"

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

// int main(int ac, char **av, char **env)
// {
//     char *line;
//     char **cmds;

//     if (ac != 1)
//         do_with_ac(ac, av);
//     while (*env)
//         _env().create(*(env++));
//     while (1)
//     {
//         line = readline("$> ");
//         if (_string().length(line) > 0)
//         {
//             if (_string().equals(line, "exit"))
//                 break;
//             cmds = buffer_into_array(line);
//             while (cmds && *cmds)
//                 _command().create(*(cmds++));
//             add_history(line);
//         }
//         _command().execute();
//         free_arrays(cmds);
//         free(line);
//         line = NULL;
//         cmds = NULL;
//     }
//     return (0);
// }

int main(int ac, char **av, char **env)
{
    char *line;
    char **cmds;

    (void)av;
    if (ac != 1)
        return (0);
    while (*env)
    {
        _env().create(_string().dup(*env));
        ++env;
    }
    while (1)
    {
        line = readline("$> ");
        if (_string().length(line) == 0)
            continue;
        else
            add_history(line);
        cmds = buffer_into_array(line);
        print_arrays(cmds);
        // while (*cmds)
        // {
        //     _command().create(*(cmds++));
        // }
        // _command().execute();
        free_arrays(cmds);
        free(line);
        line = NULL;
    }
    return (0);
}