#include "lemin.h"

t_data	*create_data_struct(void)
{
	t_data *data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
	{
//		error();
		exit(1);
	}
	data->ants = -1;
	data->q_rooms = 0;
	data->start = NULL;
	data->end = NULL;
	data->path = NULL; // ?
	return (data);
}

t_room	*create_room(char *name, int num)
{
	t_room *room;

	if ((room = (t_room *)malloc(sizeof(t_room))) == NULL)
	{
//		error()
		exit(1);
	}
	if ((room->name = ft_strdup(name)) == NULL)
	{
//		error()
		exit(1);
	}
	room->num = num;
	room->next_num = NULL;
	room->n_links = 0;
	room->links = NULL;
}

int main()
{
	t_data	*data;

	data = create_data_struct();
	get_data(data);
	return 0;
}