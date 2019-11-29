/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:47:23 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:47:26 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_vector_init(t_int_vector *int_vector)
{
	int_vector->size = 0;
	int_vector->capacity = 16;
	int_vector->data = (int*)malloc(int_vector->capacity * sizeof(int));
	if (!int_vector->data)
		return (1);
	return (0);
}
