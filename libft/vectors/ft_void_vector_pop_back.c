/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_pop_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:54 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:48:55 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_void_vector_pop_back(t_void_vector *v_vector)
{
	if (v_vector->size <= 0)
		return (0);
	v_vector->size--;
	return (v_vector->data[v_vector->size]);
}
