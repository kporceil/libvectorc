/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_delone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kporceil <kporceil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:50:42 by kporceil          #+#    #+#             */
/*   Updated: 2024/12/14 22:55:55 by kporceil         ###   ########lyon.fr   */
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

t_err	vector_delone(t_vector *vector, size_t index)
{
	ft_memmove(vector->tab + (index * vector->size_elem),
			vector->tab + ((index + 1) * vector->size_elem),
			(vector->len - (index + 1)) * vector->size_elem);
	--vector->len;
	return (NO_ERR);
}
