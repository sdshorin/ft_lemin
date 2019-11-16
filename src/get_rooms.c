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

static int		get_room_params(char *str, t_room *room, t_data *data)
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

static t_room	*del_room(t_room *room)
{
	if (room->name != NULL)
		ft_strdel(&(room->name));
	free(room);
	return (NULL);
}

static t_room	*create_room(char *str, t_data *data)
{
	t_room	*room;
	t_room	*validate;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	if ((get_room_params(str, room, data)) == -1)
	{
		return (del_room(room));
	}
	validate = data->first;
	while (validate != NULL)
	{
		if (ft_strequ(validate->name, room->name) == 1)
			return (del_room(room)); // Здесь не должно выводиться сообщение об ошибке? Возвращается NULL в get_room, ошибка выводится там.
		validate = validate->next;
	}
	room->next = NULL;
	room->level = 0;
	room->q_links = 0;
	room->index = data->q_rooms++;
	room->recipe = 0;
	room->links = NULL;

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
			last = last->next; // может, так же использовать last->tail, как с get_input? // здесь это сделано при помощи static переменной, это быстрее и проще добавления новых переменных в структуру
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
