/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_recipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:32:47 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/28 19:32:53 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	make_first_recipe(t_recipe prev_recipe, t_room *room)
{
	room->recipe.path_cost = prev_recipe.path_cost + 1;
	ft_int_vector_reset(&room->recipe.used_old_paths);
	ft_int_vector_copy(&room->recipe.used_old_paths,
								&prev_recipe.used_old_paths);
}

void	add_start(t_queue *queue, t_data *data)
{
	size_t		i;
	void		**v_vector;

	data->start->recipe.path_cost = 0;
	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		if (((t_room*)v_vector[i])->path_index < 0
						&& (t_room*)v_vector[i] != data->end)
		{
			make_first_recipe(data->start->recipe, (t_room*)v_vector[i]);
			add_to_queue(queue, (t_room*)v_vector[i], data->start);
		}
		else if ((t_room*)v_vector[i] == data->end && !data->add_direct_path)
			count_new_max_path_cost(data);
		i++;
	}
	data->add_direct_path = 1;
}

int		teleporte_step_back(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->prev_on_path->recipe.path_cost != -1
		&& prev_room->recipe.path_cost >= room->prev_on_path->recipe.path_cost)
		return (1);
	room->prev_on_path->recipe.path_cost = prev_room->recipe.path_cost;
	ft_int_vector_reset(&room->prev_on_path->recipe.used_old_paths);
	ft_int_vector_copy(&room->prev_on_path->recipe.used_old_paths,
									&prev_room->recipe.used_old_paths);
	if (ft_int_vector_push_back(&room->prev_on_path->recipe.used_old_paths,
														room->path_index) == 1)
		error_handler("Allocation error in teleporte??", NULL);
	ft_void_vector_reset(&room->prev_on_path->recipe.start_old_path_room);
	ft_void_vector_copy(&room->prev_on_path->recipe.start_old_path_room,
										&prev_room->recipe.start_old_path_room);
	ft_void_vector_push_back(&room->prev_on_path->recipe.start_old_path_room,
																prev_room);
	ft_void_vector_push_back(&room->prev_on_path->recipe.start_old_path_room,
																	room);
	add_to_queue(queue, room->prev_on_path, room);
	return (0);
}

int		make_recipe(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->path_index > -1 && prev_room->path_index != room->path_index)
	{
		return (teleporte_step_back(prev_room, room, queue));
	}
	if (room->recipe.path_cost != -1 &&
					prev_room->recipe.path_cost + 1 >= room->recipe.path_cost)
		return (1);
	room->recipe.path_cost = prev_room->recipe.path_cost + 1;
	ft_int_vector_reset(&room->recipe.used_old_paths);
	ft_int_vector_copy(&room->recipe.used_old_paths,
								&prev_room->recipe.used_old_paths);
	ft_void_vector_reset(&room->recipe.start_old_path_room);
	ft_void_vector_copy(&room->recipe.start_old_path_room,
								&prev_room->recipe.start_old_path_room);
	add_to_queue(queue, room, prev_room);
	return (0);
}

int		make_recipe_step_back(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->recipe.path_cost != -1 &&
					prev_room->recipe.path_cost - 1 >= room->recipe.path_cost)
		return (1);
	room->recipe.path_cost = prev_room->recipe.path_cost - 1;
	ft_int_vector_reset(&room->recipe.used_old_paths);
	ft_int_vector_copy(&room->recipe.used_old_paths,
								&prev_room->recipe.used_old_paths);
	ft_void_vector_reset(&room->recipe.start_old_path_room);
	ft_void_vector_copy(&room->recipe.start_old_path_room,
									&prev_room->recipe.start_old_path_room);
	add_to_queue(queue, room, prev_room);
	return (0);
}
