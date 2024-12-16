/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:35:56 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/13 04:36:33 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"


static void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	i = 0;
	cdest = (unsigned char *)dest;
	csrc = (const unsigned char *)src;
	if (dest > src)
		while (n-- && (dest || src))
			cdest[n] = csrc[n];
	else
	{
		while (i < n && (dest || src))
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (dest);
}

t_err	vector_add(t_vector *vector, void *value)
{
	t_err	err;
	if (vector->len == vector->alloc)
	{
		err = vector_realloc(vector);
		if (err)
			return (err);
	}
	ft_memmove(vector->tab + (vector->len * vector->size_elem), value,
		   vector->size_elem);
	vector->len++;
	return (NO_ERR);
}
