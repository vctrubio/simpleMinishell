/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei <joaribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:45:01 by joaribei          #+#    #+#             */
/*   Updated: 2022/08/15 14:19:23 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_test			t_test;
typedef struct s_memory			t_memory;
typedef struct s_node_malloc	t_node_malloc;

struct s_node_malloc
{
	t_node_malloc	*prev;
	t_node_malloc	*next;
	size_t			size;
	void			*ptr;
};

struct s_memory
{
	void	*(*malloc)(size_t __size);
	void	*(*realloc)(void *ptr, size_t size);
	void	*(*calloc)(size_t count, size_t size);
	void	(*free)(void *pointer);
	void	(*free_all)(void);
	void	*(*set)(void *pointer, int set, size_t length);
	void	*(*copy)(void *dst, const void *src, size_t size);
};

t_memory		_memory(void);

t_node_malloc	**_memory_list(void);
void			_memory_free_all(void);
void			_memory_free(void *ptr);
void			_memory_add(t_node_malloc *malloc);
void			*_memory_malloc(size_t __size);
void			*_memory_realloc(void *ptr, size_t size);
void			*_memory_calloc(size_t count, size_t size);
void			*_memory_set(void *pointer, int set, size_t length);
void			*_memory_copy(void *dst, const void *src, size_t size);

#endif // MEMORY_H
