/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_queue_pop_back.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:46 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:49:47 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_void_queue_pop_back(t_void_queue *void_queue)
{
	if (void_queue->size <= 0)
		return (0);
	void_queue->size--;
	return (void_queue->data[(void_queue->start + void_queue->size) %
		void_queue->capacity]);
}
