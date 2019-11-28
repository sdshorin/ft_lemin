/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_find_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:32:39 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/28 19:33:13 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	count_new_max_path_cost(t_data *data)
{
	data->path_quantity += 1;
	if (data->sum_path_len == 0)
		data->sum_path_len += data->ants;
	data->sum_path_len += data->end->recipe.path_cost;
	data->max_path_cost = (data->sum_path_len / data->path_quantity) - 2;
	if (data->sum_path_len % data->path_quantity)
		data->max_path_cost += 1;
}

void	reset_paths(t_data *data)
{
	t_room	*now_room;

	now_room = data->first;
	while (now_room)
	{
		now_room->prev_in_queue = 0;
		now_room->next_in_queue = 0;
		now_room->recipe_come_from = 0;
		now_room->recipe.path_cost = -1;
		ft_int_vector_reset(&now_room->recipe.used_old_paths);
		ft_void_vector_reset(&now_room->recipe.start_old_path_room);
		now_room = now_room->next;
	}
	data->end->prev_on_path = 0;
	data->end->next_on_path = 0;
	data->end->path_index = -1;
	data->start->prev_on_path = 0;
	data->start->next_on_path = 0;
	data->start->path_index = -1;
}

int		lem_in_find_paths(t_data *data)
{
	data->max_path_cost = -1;
	while (find_new_way(data))
	{
		make_new_way(data);
		count_new_max_path_cost(data);
		reset_paths(data);
	}
	return (0);
}
