/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:45:07 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 14:15:19 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "string.h"

typedef struct s_env		t_env;
typedef struct s_node_env	t_node_env;

struct s_node_env
{
	int			signal;
	char		*key;
	char		*value;
	t_node_env	*prev;
	t_node_env	*next;
};

struct s_env
{
	void *(*create)(char *hashmap);
	size_t (*size)(void);
	t_node_env **(*list)(void);
	t_node_env *(*get)(char *key);
	void (*delete)(char *key);
	char **(*to_double_pointer)(void);
	void (*update)(char ***old_env, char **new_env);
};

t_env _env(void);

t_node_env **_env_list(void);
size_t _env_size(void);
t_node_env *_env_get(char *key);
void *_env_create(char *hashmap);
void _env_delete(char *key);
char **_env_to_double_pointer(void);
void _env_update(char ***old_env, char **new_env);

#endif
