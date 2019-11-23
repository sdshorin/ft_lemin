//
// Created by Katharine Psylocke on 15/11/2019.
//

#include "lemin.h"
/*
t_room		*get_queued(t_queue *queue)
{
	t_room	*room;

	while (queue->next->next != NULL)
		queue = queue->next;
	room = queue->next->room;
	free(queue->next);
	queue->next = NULL;
	return (room);
}

t_queue		*add_to_queue(t_queue *queue, t_room *room)
{
	queue = (t_queue *) malloc(sizeof(t_queue));
	queue->room = room;
	queue->next = queue;
	return (queue);
}

t_recipe	*create_recipe(t_recipe *prev_rec, t_room *current)
{
	t_recipe *recipe;
	int i;

	recipe = (t_recipe *) malloc(sizeof(t_recipe));
		//protect malloc here;
	if (prev_rec == NULL)
	{
		recipe->len = 0;
		recipe->path[0] = current;
		recipe->q_used = 0;
		recipe->used_by = NULL;
	}
	else
	{
		recipe->len = prev_rec->len + 1;
		recipe->path = (t_room **)malloc(sizeof(t_room *) * recipe->len);
		//protect malloc here;
		i = 0;
		while (i < recipe->len)
		{
			recipe->path[i] = prev_rec->path[i];
			i++;
		}
		recipe->path[i] = current;
	}
	return recipe;
}

t_recipe	*bfs(t_data *data)
{
	t_room	*next;
	t_room	*current;
	t_queue	*queue;
	int		level;
	int		i;

	i = 0;
	data->start->level = 0;
	current = data->start;
	current->recipe = create_recipe(NULL, current);
	STOP HERE
}

*/