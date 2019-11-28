/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_pop_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:47:35 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:47:37 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_vector_pop_back(t_int_vector *int_vector)
{
	if (int_vector->size <= 0)
		return ('\0');
	int_vector->size--;
	return (int_vector->data[int_vector->size]);
}
