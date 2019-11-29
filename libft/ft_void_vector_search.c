/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:20 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:49:22 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_void_vector_search(t_void_vector *haystack, void *needle)
{
	int		i;
	int		size;

	i = 0;
	size = haystack->size;
	while (i < size)
	{
		if (haystack->data[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}
