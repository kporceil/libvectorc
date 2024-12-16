/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:29:28 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/12 19:31:56 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_err	vector_init(t_vector *vector, size_t size_elem)
{
	vector->alloc = 0;
	vector->len = 0;
	vector->size_elem = size_elem;
	vector->tab = NULL;
	return (NO_ERR);
}
