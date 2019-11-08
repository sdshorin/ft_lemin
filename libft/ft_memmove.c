/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:57:44 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	i = -1;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (source < destination)
		while (++i < len)
			destination[len - 1 - i] = source[len - 1 - i];
	else
		while (++i < len)
			destination[i] = source[i];
	return (dst);
}
