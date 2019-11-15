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


typedef struct	s_int_vector // need move to header file
{
	size_t	capacity;
	size_t	size;
	int		*data;
}				t_int_vector;

void	free_int_vector(t_int_vector *int_vector)
{
	free(int_vector->data);
}

int		init_int_vector(t_int_vector *int_vector)
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
	ft_memcpy(new_data, int_vector->data,\
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
