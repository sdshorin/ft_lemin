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

void	void_vector_free(t_void_vector *v_vector)
{
	free(v_vector->data);
}

int		void_vector_init(t_void_vector *v_vector)
{
	v_vector->size = 0;
	v_vector->capacity = 16;
	v_vector->data = (void**)malloc(v_vector->capacity * sizeof(void*));
	if (!v_vector->data)
		return (1);
	return (0);
}

int		void_vector_search(t_void_vector *haystack, void *needle)
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

int		void_vector_push_back(t_void_vector *v_vector, void *v)
{
	void	**new_data;

	if (v_vector->size < v_vector->capacity)
	{
		v_vector->data[v_vector->size] = v;
		v_vector->size++;
		return (0);
	}
	v_vector->capacity *= 2;
	new_data = (void**)malloc(v_vector->capacity * sizeof(void*));
	if (!new_data)
		return (1);
	ft_memcpy(new_data, v_vector->data,
			(v_vector->capacity / 2) * sizeof(void*));
	free(v_vector->data);
	v_vector->data = new_data;
	v_vector->data[v_vector->size] = v;
	v_vector->size++;
	return (0);
}

void	*void_vector_pop_back(t_void_vector *v_vector)
{
	if (v_vector->size <= 0)
		return (0);
	v_vector->size--;
	return (v_vector->data[v_vector->size]);
}



void pint_void_vector(t_void_vector *v_vector)
{
	size_t i;

	i = 0;
	printf("\n");
	while (i < v_vector->size)
	{
		printf("%zu - %p\n", i, v_vector->data[i]);
		i++;
	}
	printf("--------------\n");
}

void void_vector_reset(t_void_vector *src)
{
	src->size = 0;
}

void 	void_vector_copy(t_void_vector *dst, t_void_vector *src)
{
	size_t i;

	void_vector_reset(dst);
	i = 0;
	while (i < src->size)
	{
		void_vector_push_back(dst, src->data[i]);
		i++;
	}
}

