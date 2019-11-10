#include "lemin.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
t_data	*create_data_struct(void)
{
	t_data *data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
	{
		error_handler("Allocation error in create_data!");
	}
	data->ants = -1;
	data->q_rooms = 0;
	data->start = NULL;
	data->end = NULL;
	data->path = NULL; // ?
	data->first = NULL;
	return (data);
}
#pragma clang diagnostic pop

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
	t_room	*val;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
	{
		error_handler("Allocation error in create_room!");
		exit(1);
	}
	val = data->first;

	get_room_params(str, room);
	while (val != NULL)
	{
		if (val->name == room->name)
			error_handler("two rooms with same names!");
		val = val->next_room;
	}
	room->num = data->q_rooms;
	room->next_room = NULL;
	room->level = 0;
	room->n_links = 0;
	room->links = NULL;
	return (room);
}



#include <stdio.h>



void	display_data(t_data *data)
{
	int i = 0;

	printf("Ants: %d \n", data->ants);
	printf("start room: %s \n", data->start->name);
	printf("Start node connections: \n");
	while (i < data->start->n_links)
	{
		printf("  Name: %s \n", data->start->links[i]->name);
		i++;
	}
//	printf("connected with :%s", data->start->links[0]->name);
	printf("end room: %s", data->end->name);

}

int main(void)
{
	t_data	*data;
	t_room *last;

	data = create_data_struct();
	get_data(data);

	display_data(data);

	return 0;
}