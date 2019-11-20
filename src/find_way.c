



#include "lemin.h"


///////////// init start/////////////////////
void		make_first_recipe(t_recipe prev_recipe, t_room *room)
{
	room->recipe.path_cost = prev_recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&prev_recipe.used_old_paths, &room->recipe.used_old_paths);
}

void		add_start(t_queue *queue, t_room *start)
{
	size_t		i;
	void	**v_vector;

	start->recipe.path_cost = 0;
	i = 0;
	v_vector = start->links.data;
	pint_void_vector(&start->links);
	while (i < start->links.size)
	{
		if (((t_room*)v_vector[i])->path_index <= 0)
		{
			make_first_recipe(start->recipe, (t_room*)v_vector[i]);
			add_to_queue(queue, (t_room*)v_vector[i], start);
		}
		i++;
	}	
}
////////////////////// finish init start //////////////////////////


//////////////// handle free nodes //////////////////////

int make_recipe(t_recipe prev_recipe, t_room *room)
{
	if (room->recipe.path_cost != -1 && prev_recipe.path_cost + 1 >= room->recipe.path_cost)
		return (1);

	// don't shure it's nessesary
	// if (room->path_index > 0 && int_vector_is_int_in_vector(
	// 		&prev_recipe.used_old_paths, room->path_index))
	// 	return (1);
	room->recipe.path_cost = prev_recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&prev_recipe.used_old_paths, &room->recipe.used_old_paths);
	if (room->path_index > 0)
	{
		room->recipe.step_back_on_path = 0;
//		room->recipe.used_old_paths.push_back(room->path_index);
		int_vector_push_back(&room->recipe.used_old_paths, room->path_index);
	}
	return (0);
}

void handle_ordinary_room(t_room *now_room, t_queue *queue)
{
	void	**v_vector;
	size_t		i;

	i = 0;
	v_vector = now_room->links.data;
	while (i < now_room->links.size)
	{
		if (!make_recipe(now_room->recipe, (t_room *)v_vector[i]))
			add_to_queue(queue, (t_room *)v_vector[i], now_room);
		i++;
	}
}

//////////////// finish handle free nodes //////////////////////



//////////////////////// handle node which was used on old path ///////////

int		make_recipe_step_back(t_recipe prev_recipe, t_room *room)
{
	if (room->recipe.path_cost != -1 && prev_recipe.path_cost - 1 >= room->recipe.path_cost)
		return (1);
	room->recipe.path_cost = prev_recipe.path_cost - 1;
	room->recipe.step_back_on_path = 1;
	int_vector_reset(&room->recipe.used_old_paths);
	int_vector_copy(&prev_recipe.used_old_paths, &room->recipe.used_old_paths);
	return (0);
}

int 	make_recipe_from_old_path(t_room *prev_room, t_room *room)
{
	if (prev_room->prev_on_path == room)
		return make_recipe_step_back(prev_room->recipe, room);
	return make_recipe(prev_room->recipe, room);
}


void	handle_node_on_old_path(t_room	*now_room, t_queue *queue)
{
	void	**v_vector;
	size_t		i;

	if (!now_room->recipe.step_back_on_path)
	{
		if (!make_recipe_step_back(now_room->recipe, now_room->prev_on_path))
			add_to_queue(queue, now_room->prev_on_path, now_room);
		return ;
	}
	i = 0;
	v_vector = now_room->links.data;
	while (i < now_room->links.size)
	{
		if (((t_room*)v_vector[i]) != now_room->next_on_path)
		{
			if (make_recipe_from_old_path(now_room, (t_room*)v_vector[i]))
				add_to_queue(queue, (t_room*)v_vector[i], now_room);
		}
		i++;
	}
}

/////////////////////// end handle node with uesd on old path //////////


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
	add_start(&queue, data->start);
	while (queue.start)
	{
		now_room = get_from_queue(&queue);
		if (now_room->recipe.path_cost > data->max_path_cost && data->max_path_cost >= 0)
			continue ;
		if (now_room == data->end)
		{
			if (data->path_quantity < 1)
				return (-1);  //what do we have to return here ?
			else
				continue;
		}
		if (now_room->path_index > 0)
			handle_node_on_old_path(now_room, &queue);
		else
			handle_ordinary_room(now_room, &queue);
	}
	if (data->end->recipe.path_cost < 1)
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
		now_room = now_room->prev_on_path;
	}
}

t_room	*back_with_rewrite_to_old_path(t_room *now_room, int path_index, t_room *start)
{
	while (now_room->path_index < 0 && now_room != start)
	{
		now_room->path_index = path_index;
		now_room->prev_on_path = now_room->recipe_come_from;
		now_room->recipe_come_from->next_on_path = now_room;
	}
	return (now_room);
}

/*
 * Why there is a path_index and *start in the following func?
 */

t_room	*clear_part_of_old_path(t_room *now_room)
{
	now_room = now_room->recipe_come_from;
	while (now_room->recipe_come_from->path_index >= 0)
	{
		now_room->next_on_path = 0;
		now_room->prev_on_path = 0;
		now_room->path_index = -1; //maybe to path_index instead of -1?
		now_room = now_room->recipe_come_from;
	}
	return (now_room);
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
		now_room = back_with_rewrite_to_old_path(now_room, last_path, data->start);
		if (now_room == data->start)
			break ;
		now_room = clear_part_of_old_path(now_room);
	}
}
///////////// end make new ways from recipes //////////////



////////////// count_new_max_path_cost
void count_new_max_path_cost(t_data *data)
{
	if (data->sum_path_len == 0)
		data->sum_path_len += data->ants;
	data->sum_path_len += data->end->recipe.path_cost;
	data->max_path_cost = (data->sum_path_len / data->path_quantity);
	if (data->sum_path_len & data->path_quantity)
		data->max_path_cost += 1;
	data->path_quantity += 1;
}
////////////////// end count_new_max_path_cost



////////////////// reset_all_recipe
void reset_all_recipe(t_data *data)
{
	t_room *now_room;

	now_room = data->first;
	while (now_room)
	{
		now_room->recipe.path_cost = -1;
		int_vector_reset(&now_room->recipe.used_old_paths);
		now_room->recipe.step_back_on_path = 0;
	}
	data->end->prev_on_path = 0;
	data->end->next_on_path = 0;
	data->end->path_index = -1;
}
////////////////// end  reset_all_recipe



/////// lem_in main ////////


int lem_in_find_paths(t_data *data)
{
	data->max_path_cost = -1;
	while (find_new_way(data))
	{
		make_new_way(data);
		count_new_max_path_cost(data);
		reset_all_recipe(data);
	}
	return (0);
}
