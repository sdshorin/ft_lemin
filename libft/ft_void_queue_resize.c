/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_queue_resize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:50:01 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:52:37 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_void_queue_resize(t_void_queue *void_queue)
{
	void	**new_data;

	void_queue->capacity *= 2;
	new_data = (void**)malloc(void_queue->capacity * sizeof(void*));
	if (!new_data)
		return (1);
	ft_memcpy(new_data, void_queue->data + void_queue->start,\
		((void_queue->capacity / 2) - void_queue->start) * sizeof(void*));
	ft_memcpy(new_data + ((void_queue->capacity / 2) - void_queue->start) *
		sizeof(void*), void_queue->data, void_queue->start * sizeof(void*));
	free(void_queue->data);
	void_queue->data = new_data;
	void_queue->start = 0;
	return (0);
}
