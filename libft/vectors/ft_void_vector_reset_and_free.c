/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_vector_reset_and_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:10 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:51:27 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_void_vector_free(t_void_vector *v_vector)
{
	free(v_vector->data);
}

void	ft_void_vector_reset(t_void_vector *src)
{
	src->size = 0;
}
