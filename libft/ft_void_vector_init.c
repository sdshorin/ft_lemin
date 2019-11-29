/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:46 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:48:47 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_void_vector_init(t_void_vector *v_vector)
{
	v_vector->size = 0;
	v_vector->capacity = 16;
	v_vector->data = (void**)malloc(v_vector->capacity * sizeof(void*));
	if (!v_vector->data)
		return (1);
	return (0);
}
