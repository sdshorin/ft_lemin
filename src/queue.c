/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:48:23 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/28 19:48:25 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_queue(t_queue *queue)
{
	queue->start = 0;
	queue->finish = 0;
}

void	add_to_queue(t_queue *queue, t_room *room, t_room *come_from)
{
	room->recipe_come_from = come_from;
	if (room->prev_in_queue || room->next_in_queue)
		return ;
	if (!queue->start)
	{
		queue->finish = room;
		queue->start = room;
		return ;
	}
	queue->finish->next_in_queue = room;
	queue->finish = room;
}

t_room	*get_from_queue(t_queue *queue)
{
	t_room	*to_return;

	if (!queue->start)
		return (0);
	if (queue->start == queue->finish)
	{
		to_return = queue->start;
		queue->finish = 0;
		queue->start = 0;
		return (to_return);
	}
	to_return = queue->start;
	queue->start = queue->start->next_in_queue;
	to_return->prev_in_queue = 0;
	to_return->next_in_queue = 0;
	return (to_return);
}
