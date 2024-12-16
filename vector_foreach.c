/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:46:20 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/14 22:48:51 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_err	vector_foreach(t_vector *vector, void (*func)(void *))
{
	size_t	i;

	i = 0;
	while (i < vector->len)
	{
		func(vector->tab + (vector->size_elem + i));
		++i;
	}
	return (NO_ERR);
}
