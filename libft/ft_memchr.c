/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:37:45 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;
	unsigned char	cc;
	void			*result;
	size_t			i;

	i = 0;
	result = NULL;
	cc = (unsigned char)c;
	ss = (unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == cc)
		{
			result = (void *)(ss + i);
			return (result);
		}
		i++;
	}
	return (result);
}
