/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:50:19 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/15 00:38:58 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t	vector_search(t_vector *vector, void *search_value,
					bool (*search_func)(void *, void *))
{
	ssize_t	i;

	i = 0;
	while (i < (ssize_t)vector->len)
	{
		if (search_func(vector->tab + (i * vector->size_elem), search_value))
			return (i);
	}
	return (-1);
}
