/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:55:54 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/14 15:56:03 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	void_queue_free(t_void_queue *void_queue)
{
	free(void_queue->data);
}

int		void_queue_init(t_void_queue *int_queue)
{
	int_queue->size = 0;
	int_queue->capacity = 16;
	int_queue->start = 0;
	int_queue->data = (void**)malloc(int_queue->capacity * sizeof(void*));
	if (!int_queue->data)
		return (1);
	return (0);
}


int 	resize_void_queue(t_void_queue *void_queue)
{
	void		**new_data;

	void_queue->capacity *= 2;
	new_data = (void**)malloc(void_queue->capacity * sizeof(void*));
	if (!new_data)
		return (1);
	ft_memcpy(new_data, void_queue->data + void_queue->start,\
		( (void_queue->capacity / 2) - void_queue->start) * sizeof(void*));// need correction nere (+-1)
	ft_memcpy(new_data + ((void_queue->capacity / 2) - void_queue->start) * sizeof(void*),
		void_queue->data, void_queue->start * sizeof(void*)); // need correction nere (+-1)
	free(void_queue->data);
	void_queue->data = new_data;
	void_queue->start = 0;
	return (0);
}

int		t_void_queue_push(t_void_queue *void_queue, void *v)
{
	

	if (void_queue->size < void_queue->capacity)
	{
		void_queue->data[(void_queue->start + void_queue->size) % void_queue->capacity] = v;// need correction nere (+-1)
		void_queue->size++;
		return (0);
	}
	if (resize_void_queue(void_queue))
		return (-1);
	void_queue->data[void_queue->size] = v;
	void_queue->size++;
	return (0);
}

void*		void_queue_pop_back(t_void_queue *void_queue)
{
	if (void_queue->size <= 0)
		return (0);
	void_queue->size--;
	return (void_queue->data[(void_queue->start + void_queue->size) % void_queue->capacity]);// need correction nere (+-1)
}