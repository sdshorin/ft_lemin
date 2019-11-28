/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_queue_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:54 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:49:55 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_void_queue_push(t_void_queue *void_queue, void *v)
{
	if (void_queue->size < void_queue->capacity)
	{
		void_queue->data[(void_queue->start + void_queue->size) %
			void_queue->capacity] = v;
		void_queue->size++;
		return (0);
	}
	if (ft_void_queue_resize(void_queue))
		return (-1);
	void_queue->data[void_queue->size] = v;
	void_queue->size++;
	return (0);
}
