/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:53:46 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/13 05:28:26 by kporceil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

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

t_err	vector_realloc(t_vector *vector)
{
	void	*new_tab;

	if (!vector->alloc)
		vector->alloc = VECTOR_SIZE;
	else
		vector->alloc *= 2;
	new_tab = malloc(vector->alloc * vector->size_elem);
	if (!new_tab)
	{
		free(vector->tab);
		return (MALLOC_ERR);
	}
	ft_memmove(new_tab, vector->tab, vector->len * vector->size_elem);
	free(vector->tab);
	vector->tab = new_tab;
	return (NO_ERR);
}
