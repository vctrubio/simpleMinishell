#include "../../includes/env.h"

t_env _env(void)
{
    static t_env _env = {
        _env_create,
        _env_get
    };

    return (_env);
}

t_node_env **_env_list(void)
{
    static t_node_env *node;

    return (&node);
}
