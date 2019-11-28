/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_push_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:47:44 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:51:47 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_vector_push_back(t_int_vector *int_vector, int i)
{
	int	*new_data;

	if (int_vector->size < int_vector->capacity)
	{
		int_vector->data[int_vector->size] = i;
		int_vector->size++;
		return (0);
	}
	int_vector->capacity *= 2;
	new_data = (int*)malloc(int_vector->capacity * sizeof(int));
	if (!new_data)
		return (1);
	ft_memcpy(new_data, int_vector->data,
		(int_vector->capacity / 2) * sizeof(int));
	free(int_vector->data);
	int_vector->data = new_data;
	int_vector->data[int_vector->size] = i;
	int_vector->size++;
	return (0);
}
