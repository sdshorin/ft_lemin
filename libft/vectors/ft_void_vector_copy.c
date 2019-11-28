/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:38 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:51:08 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_void_vector_copy(t_void_vector *dst, t_void_vector *src)
{
	size_t	i;

	ft_void_vector_reset(dst);
	i = 0;
	while (i < src->size)
	{
		ft_void_vector_push_back(dst, src->data[i]);
		i++;
	}
}
