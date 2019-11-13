//
// Created by Katharine Psylocke on 13/11/2019.
//

#include "lemin.h"


void	get_room_params(char *str, t_room *room)
{
	int 	name_len;
	int 	num_len;
	int		x;
	int		y;

	name_len = ft_strchr_pos(str, ' ');
	if (name_len == 0)
		error_handler("Room name invalid!");
	room->name = ft_strsub(str, 0, name_len);
	str += name_len + 1;
	x = ft_atoi(str);
	num_len = ft_numlen(str);
	if ((x == -1 || x == 1) && num_len > 1)
		error_handler("Room coordinates invalid!");
	room->x = x;
	str += num_len;
	y = ft_atoi(str);
	if ((y == -1 || y == 1) && ft_numlen(str) > 1)
		error_handler("Room coordinates invalid!");
	room->y = y;
}

t_room	*create_room(char *str, t_data *data)
{
	t_room	*room;
	t_room	*validate;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
		error_handler("Allocation error in create_room!");
	validate = data->first;
	get_room_params(str, room);
	while (validate != NULL)
	{
		if (validate->name == room->name)
			error_handler("two rooms with same names!");
		validate = validate->next_room;
	}
	room->num = data->q_rooms;
	room->next_room = NULL;
	room->level = 0;
	room->n_links = 0;
	room->links = NULL;
	return (room);
}

void	get_room(char *str, t_data *data, int *comm)
{
	static t_room	*last;

	get_input(str, data);
	if (data->first == NULL)
	{
		data->first = create_room(str, data);
		last = data->first;
	}
	else
	{
		while (last->next_room != NULL)
			last = last->next_room;
		last->next_room = create_room(str, data);
		last = last->next_room;
	}
	data->q_rooms++;
	if (*comm == 1)
		data->start = last;
	else if (*comm == -1)
		data->end = last;
	*comm = 0;
}