



#include "lemin.h"

////// Queue part
void	init_queue(t_queue *queue)
{
	queue->start = 0;
	queue->finish = 0;
}

void	add_to_queue(t_queue *queue, t_room *room, t_room *come_from)
{
	room->recipe_come_from  = come_from;
	if (room->prev_in_queue || room->next_in_queue)
		return ; //already in queue; don't care about order
	if (!queue->start)
	{
		queue->finish = room;
		queue->start = room;
		return ;
	}
	queue->finish->next_in_queue = room;
	queue->finish = room;
}


 t_room *	get_from_queue(t_queue *queue)
{
	t_room	*to_return;

	if (!queue->start)
		return (0);
	if (queue->start == queue->finish)
	{
		to_return = queue->start;
		queue->finish = 0;
		queue->start = 0;
		return (to_return);
	}
	to_return = queue->start;
	queue->start = queue->start->next_in_queue;
	return (to_return);
}
/////// Finish queue part



///////////// init start/////////////////////
int		make_first_resept(t_recipe prew_recipe, t_room *room)
{
	room->recipe.path_cost = prew_recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_pathes);
	int_vector_copy_vec(&prew_recipe.used_old_pathes, &room->recipe.used_old_pathes);
}

int		add_start(t_queue *queue, t_room *start)
{
	int		i;
	void	**v_vector;

	start->recipe.path_cost = 0;
	i = 0;
	v_vector = start->links->data;
	while (i < start->links->size)
	{
		if (((t_room*)v_vector[i])->path_index <= 0)
		{
			make_first_resept(start->recipe, (t_room*)v_vector[i]);
			add_to_queue(queue, (t_room*)v_vector[i], start);
		}
		i++;
	}	
}
////////////////////// finish init start //////////////////////////


//////////////// handle free nodes //////////////////////

int make_recipt(t_recipe prew_recipe, t_room *room)
{
	if (room->recipe.path_cost != -1 && prew_recipe.path_cost + 1 >= room->recipe.path_cost)
		return (1);

	// don't shure it's nessesary
	if (room->path_index > 0 && int_vector_is_int_in_vector(&prew_recipe.used_old_pathes, room->path_index))
		return (1);
	room->recipe.path_cost = prew_recipe.path_cost + 1;
	int_vector_reset(&room->recipe.used_old_pathes);
	int_vector_copy_vec(&prew_recipe.used_old_pathes, &room->recipe.used_old_pathes);
	if (room->path_index > 0)
	{
		room->recipe.step_back_on_path = 0;
		room->recipe.used_old_pathes.push_back(room->path_index);
	}
	return (0);
}

void handle_ordinary_room(t_room *now_room, t_queue *queue)
{
	void	**v_vector;
	int		i;

	i = 0;
	v_vector = now_room->links->data;
	while (i < now_room->links->size)
	{
		if (make_recipt(now_room->recipe, (t_room*)v_vector[i]))
			add_to_queue(queue, (t_room*)v_vector[i], now_room);
		i++;
	}
}

//////////////// finish handle free nodes //////////////////////



//////////////////////// handle node with uesd on old path ///////////

int make_recipt_step_back(t_recipe prew_recipe, t_room *room)
{
	if (room->recipe.path_cost != -1 && prew_recipe.path_cost - 1 >= room->recipe.path_cost)
		return (1);
	room->recipe.path_cost = prew_recipe.path_cost - 1;
	room->recipe.step_back_on_path = 1;
	int_vector_reset(&room->recipe.used_old_pathes);
	int_vector_copy_vec(&prew_recipe.used_old_pathes, &room->recipe.used_old_pathes);
	return (0);
}

int make_recipt_from_old_path(t_room *prew_room, t_room *room)
{
	if (prew_room->prev_on_path == room)
		return make_recipt_step_back(prew_room->recipe, room);
	return make_recipt(prew_room->recipe, room);
}


void handle_node_on_old_path(t_room	*now_room, t_queue *queue)
{
	void	**v_vector;
	int		i;

	if (!now_room->recipe.step_back_on_path)
	{
		if (!make_recipt_step_back(now_room->recipe, now_room->prev_on_path))
			add_to_queue(queue, now_room->prev_on_path, now_room);
		return ;
	}
	i = 0;
	v_vector = now_room->links->data;
	while (i < now_room->links->size)
	{
		if (((t_room*)v_vector[i]) != now_room->next_on_path)
		{
			if (make_recipt_from_old_path(now_room, (t_room*)v_vector[i]))
				add_to_queue(queue, (t_room*)v_vector[i], now_room);
		}
		i++;
	}
}

/////////////////////// end handle node with uesd on old path //////////

///////////////// find new way iteration /////////////
int find_new_way(t_data *data)
{
	t_queue queue;
	t_room	*now_room;

	init_queue(&queue);
	add_start(&queue, data->start);
	while (queue.start)
	{
		now_room = get_from_queue(&queue);
		if (now_room->recipe.path_cost > data->max_path_cost && data->max_path_cost >= 0)
			continue ;
		if (now_room == data->end)
			if (data->path_quantity < 1)
				return ;
			else
				continue ;
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




///////////// make new ways from reciptes //////////////

void rename_old_path(t_room *now_room, int path_index, t_room *end)
{
	while (now_room != end)
	{
		now_room.path_index = path_index;
		now_room = now_room.prev_on_path;
	}
}

t_room *back_with_rewrite_to_old_path(t_room *now_room, int path_index, t_room *start)
{
	while (now_room->path_index < 0 && now_room != start)
	{
		now_room->path_index = path_index;
		now_room->prev_on_path = now_room->recipe_com_efrom;
		now_room->recipe_come_from->next_on_path = now_room;
	}
	return (now_room);
}

t_room *clear_part_of_old_path(t_room *now_room, int path_index, t_room *start)
{
	now_room = now_room->recipe_come_from;
	while (now_room->recipe_come_from->path_index >= 0)
	{
		now_room->next_on_path = 0;
		now_room->prev_on_path = 0;
		now_room->path_index = -1;
		now_room = now_room->recipe_come_from;
	}
	return (now_room);
}

void make_new_way(t_data *data)
{
	int last_path;
	t_room	*now_room;

	now_room = data->end;
	last_path = 0;
	int_vector_push_front(&data->end->recipe.used_old_pathes, data->path_quantity);
	while (data->end->recipe.used_old_pathes.size > 0)
	{
		last_path = int_vector_pop_back(&data->end->recipe.used_old_pathes);
		rename_old_path(now_room, last_path, data->end);
		now_room = back_with_rewrite_to_old_path(now_room, last_path, data->start);
		if (now_room == data->start)
			break ;
		now_room = clear_part_of_old_path(now_room);
	}
}
///////////// end make new ways from reciptes //////////////



////////////// count_new_max_path_cost
void count_new_max_path_cost(t_data *data)
{
	if (data->sum_path_len == 0)
		data->sum_path_len += data->ants;
	data->sum_path_len += data->end.recipe.path_cost;
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
		now_room->s_recipe.path_cost = -1;
		int_vector_reset(&now_room->s_recipe.used_old_pathes);
		now_room->step_back_on_path = 0;
	}
	data->end.prev_on_path = 0;
	data->end.next_on_path = 0;
	data->end.path_index = -1;
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
