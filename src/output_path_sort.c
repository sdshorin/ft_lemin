

#include "lemin.h"






void write_to_recipe_path_len(t_room *room)
{
	t_room	*now_room;
	int		i;

	i = 0;
	now_room = room;
	if (room->path_index < 0)
		return ;
	while (now_room)
	{
		i++;
		now_room = now_room->next_on_path;
	}
	room->recipe.path_cost = i;
}

void set_all_path_len(t_data *data)
{
	size_t	i;
	void	**v_vector;

	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		if (((t_room*)v_vector[i])->path_index >  -1)
			write_to_recipe_path_len((t_room*)v_vector[i]);
		else if (((t_room*)v_vector[i]) == data->end)
			((t_room*)v_vector[i])->recipe.path_cost = 1;
		else
			((t_room*)v_vector[i])->recipe.path_cost = -1;
		i++;
	}
}



void swap_void_vector(void **v_vector, size_t i, size_t j)
{
	void *temp;

	temp = v_vector[i];
	v_vector[i] = v_vector[j];
	v_vector[j] = temp;
}

void sort_paths(t_data *data)
{
	size_t	i;
	size_t	j;
	void	**v_vector;

	i = 0;
	set_all_path_len(data);
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		j = i;
		while (j < data->start->links.size)
		{
			if (((t_room*)v_vector[i])->recipe.path_cost >
					((t_room*)v_vector[j])->recipe.path_cost)
				swap_void_vector(v_vector, i, j);
			j++;
		}
		i++;
	}
}