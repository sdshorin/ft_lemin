/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:47:10 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:47:15 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_int_vector_copy(t_int_vector *dst, t_int_vector *src)
{
	size_t i;

	ft_int_vector_reset(dst);
	i = 0;
	while (i < src->size)
	{
		ft_int_vector_push_back(dst, src->data[i]);
		i++;
	}
}
