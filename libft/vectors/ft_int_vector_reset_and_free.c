/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_vector_reset_and_free.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:28 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:48:30 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_vector_free(t_int_vector *int_vector)
{
	free(int_vector->data);
}

void	ft_int_vector_reset(t_int_vector *src)
{
	src->size = 0;
}
