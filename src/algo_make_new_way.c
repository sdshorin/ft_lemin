/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_make_new_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:33:28 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/28 19:33:30 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	rename_old_path(t_room *now_room, int path_index, t_room *end)
{
	while (now_room != end)
	{
		now_room->path_index = path_index;
		now_room = now_room->next_on_path;
	}
}

t_room	*create_new_path(t_room *now_room, int path_index, t_room *start)
{
	while (now_room != start && now_room->recipe_come_from->path_index < 0)
	{
		now_room->path_index = path_index;
		now_room->prev_on_path = now_room->recipe_come_from;
		now_room->recipe_come_from->next_on_path = now_room;
		now_room = now_room->recipe_come_from;
	}
	now_room->prev_on_path = now_room->recipe_come_from;
	now_room->path_index = path_index;
	return (now_room);
}

t_room	*clear_old_path(t_room *now_room, t_void_vector *start_old_path_room)
{
	t_room	*last_room_on_old_path;
	t_room	*first_free_node;
	t_room	*first_node_to_clear;
	t_room	*next_room;

	last_room_on_old_path = ft_void_vector_pop_back(start_old_path_room);
	first_free_node = ft_void_vector_pop_back(start_old_path_room);
	first_node_to_clear = now_room->prev_on_path->next_on_path;
	now_room->prev_on_path->next_on_path = now_room;
	now_room = first_node_to_clear;
	while (now_room != last_room_on_old_path)
	{
		next_room = now_room->next_on_path;
		now_room->next_on_path = 0;
		now_room->prev_on_path = 0;
		now_room->path_index = -1;
		now_room = next_room;
	}
	last_room_on_old_path->recipe_come_from = first_free_node;
	return (last_room_on_old_path);
}

void	make_new_way(t_data *data)
{
	int		last_path;
	t_room	*now_room;

	now_room = data->end;
	ft_int_vector_push_front(&data->end->recipe.used_old_paths,
					data->path_quantity);
	while (data->end->recipe.used_old_paths.size > 0)
	{
		last_path = ft_int_vector_pop_back(&data->end->recipe.used_old_paths);
		rename_old_path(now_room, last_path, data->end);
		now_room = create_new_path(now_room, last_path, data->start);
		if (now_room == data->start)
			break ;
		now_room = clear_old_path(now_room,
					&data->end->recipe.start_old_path_room);
	}
}
