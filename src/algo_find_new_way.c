

#include "lemin.h"


void	handle_room(t_room	*now_room, t_queue *queue)
{
	void	**v_vector;
	size_t		i;

	i = 0;
	v_vector = now_room->links.data;
	while (i < now_room->links.size)
	{
		if (now_room->path_index > -1 && ((t_room*)v_vector[i]) == now_room->next_on_path)
			;
		else if (now_room->path_index > -1 && ((t_room*)v_vector[i]) == now_room->prev_on_path)
			make_recipe_step_back(now_room, ((t_room*)v_vector[i]), queue);
		else 
			make_recipe(now_room, (t_room *)v_vector[i], queue);
		i++;
	}
}




int		check_can_add_way(t_data *data)
{
	if (data->path_quantity >= data->start->links.size ||
			data->path_quantity >= data->end->links.size)
		return (1);
	return (0);
}


int		find_new_way(t_data *data)
{
	t_queue	queue;
	t_room	*now_room; 

	if (check_can_add_way(data))
		return (0);
	init_queue(&queue);
	add_start(&queue, data);
	while (queue.start)
	{
		now_room = get_from_queue(&queue);

		if ((now_room->recipe.path_cost > data->max_path_cost && data->max_path_cost >= 0 )|| now_room == data->start)
			continue ;
		if (now_room == data->end)
			continue ;
		handle_room(now_room, &queue);
	}
	if (data->end->recipe.path_cost < 1 || (data->end->recipe.path_cost > data->max_path_cost && data->max_path_cost != -1))
		return (0);
	return (1);
}