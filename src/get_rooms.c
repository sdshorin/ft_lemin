/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:16 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:18 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_room(t_room *room)
{
	room->next = NULL;
	room->level = 0;
	room->q_links = 0;
	room->recipe.path_cost = -1;
//	room->recipe.step_back_on_path = 0;
	room->path_index = -1;
	room->next_in_queue = 0;
	room->prev_in_queue = 0;
	room->next_on_path = 0;
	// room->is_finish = 0;
	// room->is_start = 0;
	room->recipe_come_from = 0;
	int_vector_init(&room->recipe.used_old_paths);
	void_vector_init(&room->recipe.start_old_path_room);
	void_vector_init(&room->links);
	// room->links = NULL;
}

static t_room	*del_room(t_room *room)
{
	if (room->name != NULL)
		ft_strdel(&(room->name));
	free(room);
	return (NULL);
}

static int		get_room_params(char *str, t_room *room) //, t_data *data)
{
	int		name_len;
	int		num_len;
	int		x;
	int		y;

	name_len = ft_strchr_pos(str, ' ');
	if (name_len == 0)
		return (-1);
	if ((room->name = ft_strsub(str, 0, name_len)) == NULL)
		return (-1);
	str += name_len + 1;
	while (*str == ' ')
		str++;
	x = ft_atoi(str);
	num_len = ft_numlen(str);
	if ((x == -1 || x == 1) && num_len > 1)
		return (-1);
	room->x = x;
	str += num_len;
	y = ft_atoi(str);
	if ((y == -1 || y == 1) && ft_numlen(str) > 1)
		return (-1);
	room->y = y;
	return (0);
}

static t_room	*create_room(char *str, t_data *data)
{
	t_room	*room;
	t_room	*validate;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	if ((get_room_params(str, room)) == -1)
		return (del_room(room));
	validate = data->first;
	while (validate != NULL)
	{
		if (ft_strequ(validate->name, room->name) == 1)
			return (del_room(room));
		validate = validate->next;
	}
	init_room(room);

	// if (room->x == 4408)
	// 	data->room4408 = room;
	// else if (room->x == 6094)
	// 	data->room6094 = room;
	// else if (room->x == 9114)
	// 	data->room9114 = room;
	// else if (room->x == 6098)
	// 	data->room6098 = room;
	// else if (room->x == 6092)
	// 	data->room6092 = room;
	// else if (room->x == 7187)
	// 	data->room7187 = room;
	// else if (room->x == 6344)
	// 	data->room6344 = room;
	// else if (room->x == 4577)
	// 	data->room4577 = room;
	// else if (room->x == 8970)
	// 	data->room8970 = room;
	// else if (room->x == 6128)
	// 	data->room6128 = room;
	// else if (room->x == 7352)
	// 	data->room7352 = room;
	// else if (room->x == 7400)
	// 	data->room7400 = room;
	// else if (room->x == 8905)
	// 	data->room8905 = room;




	room->index = data->q_rooms++;

	return (room);
}

void			get_room(char *str, t_data *data, int *comm)
{
	static t_room *last;

	get_input(str, data);
	if (data->first == NULL)
	{
		data->first = create_room(str, data);
		last = data->first;
	}
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = create_room(str, data);
		last = last->next;
	}
	if (last == NULL)
		error_handler("Failed to create room!", data);
	data->q_rooms++;
	if (*comm == 1)
		data->start = last;
	else if (*comm == -1)
		data->end = last;
	*comm = 0;
}
