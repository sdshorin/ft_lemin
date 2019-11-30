/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_push_front.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:19 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:50:47 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_vector_push_front(t_int_vector *int_vector, int new_num)
{
	int		last_elem;
	size_t	i;

	if (int_vector->size > 0)
	{
		i = 0;
		last_elem = int_vector->data[int_vector->size - 1];
		while (i < int_vector->size - 1)
		{
			int_vector->data[i + 1] = int_vector->data[i];
			i++;
		}
		int_vector->data[0] = new_num;
		if (ft_int_vector_push_back(int_vector, last_elem))
			return (1);
	}
	else
	{
		if (ft_int_vector_push_back(int_vector, new_num))
			return (1);
	}
	return (0);
}
