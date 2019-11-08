#include "lemin.h"

s_map	*create_struct(void)
{
	s_map *data;

	if (!(data = (s_map *)malloc(sizeof(s_map))))
	{
//		error();
		exit(1);
	}
	data->ants = 0;
	data->q_rooms = 0;
	data->n_rooms = NULL;
	data->links = NULL;
	data->tab = NULL;
	data->path = NULL;
	return (data);
}

int main()
{
	s_map	*data;

	data = create_struct();
	get_data(data);
	return 0;
}