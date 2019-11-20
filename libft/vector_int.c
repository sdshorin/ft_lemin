/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:55:54 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/14 15:56:03 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"




void	int_vector_free(t_int_vector *int_vector)
{
	free(int_vector->data);
}

int		int_vector_init(t_int_vector *int_vector)
{
	int_vector->size = 0;
	int_vector->capacity = 16;
	int_vector->data = (int*)malloc(int_vector->capacity * sizeof(int));
	if (!int_vector->data)
		return (1);
	return (0);
}

int		int_vector_push_back(t_int_vector *int_vector, int i)
{
	int		*new_data;

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

int		int_vector_pop_back(t_int_vector *int_vector)
{
	if (int_vector->size <= 0)
		return ('\0');
	int_vector->size--;
	return (int_vector->data[int_vector->size]);
}

void 	int_vector_copy(t_int_vector *dst, t_int_vector *src)
{
	size_t i;

	int_vector_reset(dst);
	i = 0;
	while (i < src->size)
	{
		int_vector_push_back(dst, src->data[i]);
		i++;
	}
}

void int_vector_reset(t_int_vector *src)
{
	src->size = 0;
}

void int_vector_push_front(t_int_vector *int_vector, int new_num)
{
	int last_elem;
	size_t i;
	if (int_vector->size  > 0)
	{
		i = 0;
		last_elem = int_vector->data[int_vector->size - 1];
		while (i < int_vector->size - 1)
		{
			int_vector->data[i + 1] = int_vector->data[i];
			i++;
		}
		int_vector->data[0] = new_num;
		int_vector_push_back(int_vector, last_elem);
	}
	else
		int_vector_push_back(int_vector, new_num);
}