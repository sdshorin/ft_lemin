



#include "lemin.h"


///////////// init start/////////////////////



void		make_first_recipe(t_recipe prev_recipe, t_room *room)
{
	room->recipe.path_cost = prev_recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&room->recipe.used_old_paths, &prev_recipe.used_old_paths);
}

void		add_start(t_queue *queue, t_data *data)
{
	size_t		i;
	void	**v_vector;

	data->start->recipe.path_cost = 0;
	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		if (((t_room*)v_vector[i])->path_index < 0 && (t_room*)v_vector[i] != data->end)
		{
			make_first_recipe(data->start->recipe, (t_room*)v_vector[i]);
			add_to_queue(queue, (t_room*)v_vector[i], data->start);
		}
		else if ((t_room*)v_vector[i] == data->end && ! data->add_direct_path)
			count_new_max_path_cost(data);
		i++;
	}
	data->add_direct_path = 1;
}
////////////////////// finish init start //////////////////////////


//////////////// handle free nodes //////////////////////

int teleporte_step_back(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->prev_on_path->recipe.path_cost != -1 && prev_room->recipe.path_cost >= room->prev_on_path->recipe.path_cost)
		return (1);

	// room->prev_on_path->recipe_come_from  = room;
	// if (room->prev_on_path->is_start)
	// 	return (0);
	room->prev_on_path->recipe.path_cost = prev_room->recipe.path_cost;
	int_vector_reset(&room->prev_on_path->recipe.used_old_paths);
	int_vector_copy(&room->prev_on_path->recipe.used_old_paths, &prev_room->recipe.used_old_paths);
	int_vector_push_back(&room->prev_on_path->recipe.used_old_paths, room->path_index);

	void_vector_reset(&room->prev_on_path->recipe.start_old_path_room);
	void_vector_copy(&room->prev_on_path->recipe.start_old_path_room, &prev_room->recipe.start_old_path_room);
	void_vector_push_back(&room->prev_on_path->recipe.start_old_path_room, prev_room);
	void_vector_push_back(&room->prev_on_path->recipe.start_old_path_room, room);
	add_to_queue(queue, room->prev_on_path, room);

	return (0);

	// room->prev_on_path
}



int make_recipe(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->path_index > -1 && prev_room->path_index != room->path_index)
	{
		return teleporte_step_back(prev_room, room, queue);
	}

	if (room->recipe.path_cost != -1 && prev_room->recipe.path_cost + 1 >= room->recipe.path_cost)
		return (1);

	room->recipe.path_cost = prev_room->recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&room->recipe.used_old_paths, &prev_room->recipe.used_old_paths);
	void_vector_reset(&room->recipe.start_old_path_room);
	void_vector_copy(&room->recipe.start_old_path_room, &prev_room->recipe.start_old_path_room);
	add_to_queue(queue, room, prev_room );

// 	if (room->path_index > -1)
// 	{
// 		// room->recipe.step_back_on_path = 0;
// //		room->recipe.used_old_paths.push_back(room->path_index);
// 		int_vector_push_back(&room->recipe.used_old_paths, room->path_index);
// 	}
	return (0);
}

// void handle_ordinary_room(t_room *now_room, t_queue *queue)
// {
// 	void	**v_vector;
// 	size_t		i;

// 	i = 0;
// 	v_vector = now_room->links.data;
// 	while (i < now_room->links.size)
// 	{
// 		make_recipe(now_room, (t_room *)v_vector[i], queue);
// 			// add_to_queue(queue, (t_room *)v_vector[i], now_room);
// 		i++;
// 	}
// }

//////////////// finish handle free nodes //////////////////////



//////////////////////// handle node which was used on old path ///////////

int		make_recipe_step_back(t_room *prev_room, t_room *room, t_queue *queue)
{
	if (room->recipe.path_cost != -1 && prev_room->recipe.path_cost - 1 >= room->recipe.path_cost)
		return (1);
	room->recipe.path_cost = prev_room->recipe.path_cost - 1;
	// room->recipe.step_back_on_path = 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&room->recipe.used_old_paths, &prev_room->recipe.used_old_paths);
	void_vector_reset(&room->recipe.start_old_path_room);
	void_vector_copy(&room->recipe.start_old_path_room, &prev_room->recipe.start_old_path_room);
	add_to_queue(queue, room, prev_room );
	return (0);
}

// int 	make_recipe_from_old_path(t_room *prev_room, t_room *room, t_queue *queue)
// {
// 	if (prev_room->prev_on_path == room)
// 		return make_recipe_step_back(prev_room, room, queue);
// 	return make_recipe(prev_room, room, queue);
// }


// void	handle_node_on_old_path(t_room	*now_room, t_queue *queue)
// {
// 	void	**v_vector;
// 	size_t		i;

// 	// if (!now_room->recipe.step_back_on_path)
// 	// {
// 	// 	if (!make_recipe_step_back(now_room->recipe, now_room->prev_on_path))
// 	// 		add_to_queue(queue, now_room->prev_on_path, now_room);
// 	// 	return ;
// 	// }
// 	i = 0;
// 	v_vector = now_room->links.data;
// 	while (i < now_room->links.size)
// 	{
// 		if (((t_room*)v_vector[i]) != now_room->next_on_path)
// 		{
// 			make_recipe_from_old_path(now_room, (t_room*)v_vector[i], queue);
// 				// add_to_queue(queue, room, prev_room );
// 		}
// 		i++;
// 	}
// }

/////////////////////// end handle node with uesd on old path //////////


/////////// handle room - new variant ////




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


///////////



int		check_can_add_way(t_data *data)
{
	if (data->path_quantity >= data->start->links.size ||
			data->path_quantity >= data->end->links.size)
		return (1);
	return (0);
}


///////////////// find new way iteration /////////////
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
		// if (now_room->index == 4028 && data->path_quantity == 12)
		// 	printf("-.-\n");
		if ((now_room->recipe.path_cost > data->max_path_cost && data->max_path_cost >= 0 )|| now_room == data->start)
			continue ;
		if (now_room == data->end)
			continue ;
		// if (now_room->path_index > -1)
		// 	handle_node_on_old_path(now_room, &queue);
		// else
		// 	handle_ordinary_room(now_room, &queue);
		handle_room(now_room, &queue);
	}
	if (data->end->recipe.path_cost < 1 || (data->end->recipe.path_cost > data->max_path_cost && data->max_path_cost != -1))
		return (0);
	return (1);
}
///////////////// end find new way iteration /////////////




///////////// make new ways from recipes //////////////

void	rename_old_path(t_room *now_room, int path_index, t_room *end)
{
	while (now_room != end)
	{
		now_room->path_index = path_index;
		now_room = now_room->next_on_path;
	}
}

// t_room	*back_with_rewrite_to_old_path(t_room *now_room, int path_index, t_room *start)
// {
// 	// if (now_room->index == 4028)
// 		// printf("find it");
// 	// if (now_room->path_index > -1)
// 	// 	return (now_room);
// 	now_room->prev_on_path = now_room->recipe_come_from;
// 	now_room->recipe_come_from->next_on_path = now_room;
// 	now_room = now_room->recipe_come_from;
// 	while (now_room->path_index < 0 && now_room != start)
// 	{
// 		// if (now_room->index == 4028)
// 		// 	printf("find it");
// 		// if (now_room->recipe_come_from == now_room->next_on_path)
// 		now_room->path_index = path_index;
// 		now_room->prev_on_path = now_room->recipe_come_from;
// 		now_room->recipe_come_from->next_on_path = now_room;
// 		// if (now_room->recipe_come_from->next_on_path == now_room->recipe_come_from->prev_on_path)
// 		// 	printf("find it!\n");
// 		now_room = now_room->recipe_come_from;
// 	}
// 	return (now_room);
// }


// t_room	*clear_part_of_old_path(t_room *now_room, t_void_vector *start_old_path_room)
// {
// 	t_room *last_room_on_old_path;
// 	t_room *first_free_node;
// 	// t_room *next_room;

// // if (!now_room->recipe_come_from)
// // 			printf("find!\n");
// 	last_room_on_old_path = void_vector_pop_back(start_old_path_room);
// 	first_free_node = void_vector_pop_back(start_old_path_room);
// 	now_room = now_room->recipe_come_from;
// 	while (now_room != last_room_on_old_path)
// 	{
// 		// next_room = now_room->next_on_path;
// 		now_room->next_on_path = 0;
// 		now_room->prev_on_path = 0;
// 		now_room->path_index = -1;
// 		// if (!next_room->recipe_come_from)
// 		// 	printf("find!\n");
// 		// now_room = next_room;
// 		now_room = now_room->recipe_come_from;
// 	}
// 	last_room_on_old_path->prev_on_path = first_free_node;
// 	first_free_node->next_on_path = last_room_on_old_path;
// 	return (first_free_node);
// }
//////////////////////////////////////




t_room	*create_new_path(t_room *now_room, int path_index, t_room *start)
{
	while (now_room != start && now_room->recipe_come_from->path_index < 0)
	{
		now_room->path_index = path_index;
		now_room->prev_on_path = now_room->recipe_come_from;
		now_room->recipe_come_from->next_on_path = now_room;
		now_room = now_room->recipe_come_from;
	}
	now_room->prev_on_path = now_room->recipe_come_from;
	now_room->path_index = path_index;
	return (now_room);
}

t_room	*clear_old_path(t_room *now_room, t_void_vector *start_old_path_room)
{
	t_room *last_room_on_old_path;
	t_room *first_free_node;
	t_room	*first_node_to_clear;
	t_room 	*next_room;

	last_room_on_old_path = void_vector_pop_back(start_old_path_room);
	first_free_node = void_vector_pop_back(start_old_path_room);
	first_node_to_clear = now_room->prev_on_path->next_on_path;
	now_room->prev_on_path->next_on_path = now_room;
	now_room = first_node_to_clear;
	while (now_room != last_room_on_old_path)
	{
		next_room = now_room->next_on_path;
		now_room->next_on_path = 0;
		now_room->prev_on_path = 0;
		now_room->path_index = -1;
		now_room = next_room;
	}
	last_room_on_old_path->recipe_come_from = first_free_node;
	// first_free_node->next_on_path = last_room_on_old_path;
	return (last_room_on_old_path);
}

void	make_new_way(t_data *data)
{
	int last_path;
	t_room	*now_room;

	now_room = data->end;
	last_path = 0;
	int_vector_push_front(&data->end->recipe.used_old_paths, data->path_quantity);
	while (data->end->recipe.used_old_paths.size > 0)
	{
		last_path = int_vector_pop_back(&data->end->recipe.used_old_paths);
		rename_old_path(now_room, last_path, data->end);
		now_room = create_new_path(now_room, last_path, data->start);
		if (now_room == data->start)
			break ;
		now_room = clear_old_path(now_room, &data->end->recipe.start_old_path_room);
		// if (!data->end->recipe.start_old_path_room.size || ((t_room*)data->end->recipe.start_old_path_room.data[data->end->recipe.start_old_path_room.size - 1])->prev_on_path != now_room)
		// now_room = clear_part_of_old_path(now_room, &data->end->recipe.start_old_path_room);
	}
}
///////////// end make new ways from recipes //////////////



////////////// count_new_max_path_cost
void count_new_max_path_cost(t_data *data)
{
	data->path_quantity += 1;
	if (data->sum_path_len == 0)
		data->sum_path_len += data->ants;
	data->sum_path_len += data->end->recipe.path_cost;
	data->max_path_cost = (data->sum_path_len / data->path_quantity) - 2;
	if (data->sum_path_len % data->path_quantity)
		data->max_path_cost += 1;
	// printf("max path cost = %d\n", data->max_path_cost);
}
////////////////// end count_new_max_path_cost



////////////////// reset_all_recipe
void reset_all_room(t_data *data)
{
	t_room *now_room;

	now_room = data->first;
	while (now_room)
	{
		now_room->prev_in_queue = 0;
		now_room->next_in_queue = 0;
		now_room->recipe_come_from = 0;
		now_room->recipe.path_cost = -1;
		int_vector_reset(&now_room->recipe.used_old_paths);
		void_vector_reset(&now_room->recipe.start_old_path_room);
		now_room->recipe.step_back_on_path = 0;
		now_room = now_room->next;
	}
	data->end->prev_on_path = 0;
	data->end->next_on_path = 0;
	data->end->path_index = -1;
	data->start->prev_on_path = 0;
	data->start->next_on_path = 0;
	data->start->path_index = -1;
}
////////////////// end  reset_all_recipe

// void print_path_len(t_data *data)
// {
// 		size_t	i;
// 	t_room *now_room;
// 	void **v_vector;
// 	i = 0;
// 	int sum =0;
// 	v_vector = data->start->links.data;
// 	while (i < data->start->links.size)
// 	{
// 		if (((t_room*)v_vector[i])->path_index >  -1)
// 		{
// 			now_room = ((t_room*)v_vector[i]);
// 			sum++;
// 			t_room *prev_room = now_room;
// 			while (now_room != data->end)
// 			{
// 				sum++;
// 				prev_room = now_room;
// 				now_room = now_room->next_on_path;
// 			}
// 		}
// 		i++;
// 	}
// }

/////// lem_in main ////////


int lem_in_find_paths(t_data *data)
{
	data->max_path_cost = -1;
	while (find_new_way(data))
	{ 
		make_new_way(data);
		count_new_max_path_cost(data);
		reset_all_room(data);
	}
	return (0);
}
