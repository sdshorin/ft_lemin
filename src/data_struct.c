//
// Created by Katharine Psylocke on 13/11/2019.
//

#include "lemin.h"

t_data	*create_data_struct(void)
{
	t_data *data;

	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		error_handler("Allocation error in create_data!");
	data->ants = -1;
	data->q_rooms = 0;
	data->first = NULL;
	data->start = NULL;
	data->end = NULL;
	data->path = NULL; // ?
	data->input_head = NULL;
	data->input_tail = NULL;
	data->input_strings = 0;
	return (data);
}



#include <stdio.h>



void	debug_display_data(t_data *data)
{
	int i = 0;
	int j = 0;
	t_room *room;

	printf("Ants: %d\n", data->ants);
	room = data->first;
	while (room != NULL)
	{
		if (data->start == room)
			printf("##start\n");
		else if (data->end == room)
			printf("##end\n");
		printf("Room: %s\n", room->name);
		printf("It's coords: x = %d y = %d\n", room->x, room->y);
		printf("It's links:\n");
		while (j < room->n_links)
		{
			printf(" Link #%d name: %s\n", j, room->links[j]->name);
			j++;
		}
		printf("\n");
		j = 0;
		room = room->next_room;
	}
}

static void	destroy_rooms(t_data *data)
{
	t_room *cur;
	t_room *prev;

	cur = data->first;
	if (cur == NULL)
		return ;
	while (cur != NULL)
	{
		ft_strdel(&(cur->name));
		free(cur->links);
		prev = cur;
		cur = cur->next_room;
		free(prev);
		prev = NULL;
	}
}

void		destroy_data(t_data *data)
{
	if (data != NULL)
	{
		destroy_rooms(data);
		free(data);
		data = NULL;
	}
}
