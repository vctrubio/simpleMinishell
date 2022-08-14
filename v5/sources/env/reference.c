#include "../../includes/env.h"

t_node_env **_env_list(void)
{
    static t_node_env *node;

    return (&node);
}

t_env _env(void)
{
    static t_env _env = {
        _env_create,
        _env_size,
        _env_list,
        _env_get,
        _env_to_double_pointer
    };

    return (_env);
}
