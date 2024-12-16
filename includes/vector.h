/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:24:50 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/15 00:37:29 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# ifndef VECTOR_SIZE
#  define VECTOR_SIZE 5
# endif

# include <stddef.h>
# include <stdbool.h>
# include <sys/types.h>

typedef struct s_vector
{
	size_t	alloc;
	size_t	len;
	size_t	size_elem;
	void	*tab;
}			t_vector;

typedef enum e_err
{
	NO_ERR,
	MALLOC_ERR,
	READ_ERR,
	WRITE_ERR,
}			t_err;

t_err		vector_init(t_vector *vector, size_t size_elem);
t_err		vector_add(t_vector *vector, void *value);
t_err		vector_realloc(t_vector *vector);
t_err		vector_free(t_vector *vector);
t_err		vector_foreach(t_vector *vector, void (*func)(void *));
t_err		vector_delone(t_vector *vector, size_t index);
ssize_t		vector_search(t_vector *vector, void *search_value,
				bool (*search_func)(void *, void *));

#endif
