

#include "lemin.h"




void make_ant(int ant_index, t_ant **first_ant, t_room *next_room, t_ant **last_ant)
{
	t_ant *now_ant;
	
	now_ant = (t_ant*)malloc(sizeof(t_ant));
	now_ant->ant_index = ant_index;
	now_ant->now_room = next_room;
	now_ant->next_ant = 0;
	now_ant->to_delete = 0;
	if (*last_ant == 0)
	{
		*last_ant = now_ant;
		now_ant->prev_ant = 0;
		(*first_ant) = now_ant;
	}
	else
	{
		(*last_ant)->next_ant = now_ant;
		now_ant->prev_ant = *last_ant;
		*last_ant = now_ant;
	}
	
}

void write_to_recipte_path_len(t_room *room)
{
	t_room *now_room;
	int i;

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
	void **v_vector;
	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		if (((t_room*)v_vector[i])->path_index >  -1)
			write_to_recipte_path_len((t_room*)v_vector[i]);
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
	void **v_vector;

	i = 0;
	set_all_path_len(data);
	v_vector = data->start->links.data;
	while (i < data->start->links.size)
	{
		j = i;
		while (j < data->start->links.size)
		{
			if (((t_room*)v_vector[i])->recipe.path_cost > ((t_room*)v_vector[j])->recipe.path_cost)
				swap_void_vector(v_vector, i, j);
			j++;
		}
		i++;
	}
}

// void create_now_ants(t_data *data, int *ant_index, t_ant** first_ant, t_room *start)
void create_now_ants(t_data *data, int *ant_index, t_ant** first_ant, t_ant** last_ant)
{
	size_t	i;
	void **v_vector;
	if (data->ants <= 0)
		return ;
	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size && data->ants > 0)
	{
		t_room *now= v_vector[i];
		if (((t_room*)v_vector[i])->path_index >= 0 || ((t_room*)v_vector[i]) == data->end)
		{
			if (((t_room *)v_vector[i])->recipe.path_cost >= data->max_path_cost + 2)
			{
				i++;
				continue;
			}
			make_ant(*ant_index, first_ant, ((t_room*)v_vector[i]), last_ant);
			if (((t_room*)v_vector[i]) != data->end)
				((t_room *)v_vector[i])->recipe.path_cost++;
			(*ant_index)++;
			data->ants--;
		}
		now = 0;
		i++;
	}	
}


t_ant *delete_ant(t_ant *ant, t_ant **first_ant, t_ant **last_ant)
{
	t_ant* to_return;

	if (*first_ant == ant)
		*first_ant = ant->next_ant;
	if (*last_ant == ant)
		*last_ant = ant->prev_ant;
	if (ant->prev_ant != NULL)
		ant->prev_ant->next_ant = ant->next_ant;
	to_return = ant->next_ant;
	if (ant->next_ant != NULL)
		ant->next_ant->prev_ant = ant->prev_ant;
	free(ant);
	// ft_memdel((void **)&ant);
	return (to_return);
}

void move_now_ants(t_ant **first_ant, t_ant **last_ant) //, t_room *end)
{
	int need_whitespace;
	t_ant	*ant;

	ant = *first_ant;
	need_whitespace = 0;
	while (ant)
	{
		// if (ant->to_delete)
		// {
		// 	ant = delete_ant(ant);
		// 	continue ;
		// }
		if (need_whitespace)
			write(1, " ", 1);
		need_whitespace = 1;
		write(1, "L", 1);
		ft_putnbr(ant->ant_index);
		write(1, "-", 1);
		ft_putstr(ant->now_room->name);
		// if (ant->now_room == end)
		// 	ant->to_delete = 1;
		ant->now_room = ant->now_room->next_on_path;
		if (!ant->now_room)
			ant = delete_ant(ant, first_ant, last_ant);
		else
			ant = ant->next_ant;
	}
}


void run_ants_print_answer(t_data *data)
{
	t_ant	*first_ant;
	t_ant	*last_ant;
	int		ant_index;
	
	first_ant = 0;
	ant_index = 1;
	last_ant = 0;
	sort_paths(data);
	while(data->ants > 0 || first_ant)
	{
		create_now_ants(data, &ant_index, &first_ant, &last_ant);
		move_now_ants(&first_ant, &last_ant); //, data->end);
		if (data->ants > 0 || first_ant)
			write(1, "\n", 1);
	}
}