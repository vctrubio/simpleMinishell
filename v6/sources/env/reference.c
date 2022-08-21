/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reference.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:42:41 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 11:42:42 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        _env_delete,
        _env_to_double_pointer,
        _env_update
    };

    return (_env);
}
