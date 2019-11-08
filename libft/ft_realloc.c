/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:01:16 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *mem, size_t size, size_t add)
{
	void *result;

	if (size + add == 0)
		return (NULL);
	result = ft_memalloc(size + add);
	ft_bzero(result, size + add);
	if (result == NULL)
		return (NULL);
	result = ft_memcpy(result, mem, size);
	free(mem);
	return (result);
}
