/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_push_back.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:01 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:52:11 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_void_vector_push_back(t_void_vector *v_vector, void *v)
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
