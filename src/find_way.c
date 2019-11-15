



#include "lemin.h"

////// Queue part
void	init_queue(t_queue *queue)
{
	queue->start = 0;
	queue->finish = 0;
}

void	add_to_queue(t_queue *queue, t_room *room)
{
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








int		add_start(t_queue *queue, t_room *start)
{
	int		i;
	void	**v_vector;

	start->recipe.path_cost = 0;
	if (start->recipe.need_init_vector)
		void_vector_init(&(start->recipe.used_old_pathes));
	i = 0;
	v_vector = start->links->data;
	while (i < start->links->size)
	{
		if (!((t_room*)v_vector[i])->links->size)
			add_to_queue(queue, (t_room*)v_vector[i]);
	}	
}


int find_new_way(t_data *data)
{
	t_queue queue;
	t_room	*now_room;

	init_queue(&queue);
	add_start(&queue, data->start);

	while (queue.start)
	{
		now_room = get_from_queue(&queue);
		if (node_on_path)
	//	if (is_finish(data, now_room)   // наилучшие рецепты не перезаписываются - поэтому в конце алгоритма в финише будет хранится наилучший рецепт 	
	
		// if t_node is finish:
		// 	finish_recipt.pueh_back(t_node)
		// 	continue
	}
			


}