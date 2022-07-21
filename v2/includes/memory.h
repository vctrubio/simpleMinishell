/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaribei < joaribei@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:17:30 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/01 14:45:34 by joaribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_malloc
{
	size_t			size;
	void			*ptr;
	struct s_malloc	*next;
	struct s_malloc	*prev;
}	t_malloc;

typedef struct s_memory
{
	int			(*free_all)(void);
	int			(*free)(void *pointer);
	void		*(*malloc)(size_t __size);
	void		*(*realloc)(void *ptr, size_t size);
	void		*(*calloc)(size_t count, size_t size);
	void		*(*set)(void *pointer, int set, size_t length);
	void		*(*copy)(void *dst, const void *src, size_t size);
}	t_memory;

t_memory	_memory(void);

t_malloc	*_memory_find_maloc(void *ptr);

int			_memory_free_all(void);
int			_memory_free(void *ptr);
void		*_memory_malloc(size_t __size);
void		*_memory_calloc(size_t count, size_t size);
void		*_memory_realloc(void *ptr, size_t size);

void		_memory_add_maloc(t_malloc **new_malloc);

void		*_memory_set(void *pointer, int set, size_t length);
void		*_memory_copy(void *dst, const void *src, size_t size);

#endif // MEMORY_H
