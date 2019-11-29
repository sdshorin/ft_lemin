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
	room->q_links = 0;
	room->recipe.path_cost = -1;
	room->path_index = -1;
	room->next_in_queue = 0;
	room->prev_in_queue = 0;
	room->next_on_path = 0;
	room->recipe_come_from = 0;
	ft_int_vector_init(&room->recipe.used_old_paths);
	ft_void_vector_init(&room->recipe.start_old_path_room);
	ft_void_vector_init(&room->links);
}

static int		check_coords(char **str, int x, int y)
{
	int i;
	int j;

	if ((ft_abs(x) == 1 && ft_numlen(str[1]) > 1) ||
			(ft_abs(y) == 1 && ft_numlen(str[2]) > 1))
		return (-1);
	i = 1;
	while (i < 3)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) != 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int		get_room_params(char *str, t_room *room)
{
	char	**splitted;
	int		i;

	i = 0;
	if ((splitted = ft_strsplit(str, ' ')) == NULL)
		return (-1);
	while (splitted[i] != NULL)
		i++;
	if (i != 3 || ft_strlen(splitted[0]) < 1)
		return (ft_strsplit_del(splitted));
	room->name = splitted[0];
	room->x = ft_atoi(splitted[1]);
	room->y = ft_atoi(splitted[2]);
	if (check_coords(splitted, room->x, room->y) == -1)
		return (ft_strsplit_del(splitted));
	ft_strdel(&(splitted[1]));
	ft_strdel(&(splitted[2]));
	free(splitted);
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
