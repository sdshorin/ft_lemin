

#include "lemin.h"




void make_ant(int ant_index, t_ant **first_ant, t_room *next_room)
{
	static t_ant *last_ant;
	t_ant *now_ant;
	
	now_ant = (t_ant*)malloc(sizeof(t_ant));
	now_ant->ant_index = ant_index;
	now_ant->now_room = next_room;
	now_ant->next_ant = 0;
	now_ant->to_delete = 0;
	if (last_ant == 0)
	{
		last_ant = now_ant;
		now_ant->prev_ant = 0;
		(*first_ant) = now_ant;
	}
	else
	{
		last_ant->next_ant = now_ant;
		now_ant->prev_ant = last_ant;
		last_ant = now_ant;
	}
	
}



void create_now_ants(int *ants, int *ant_index, t_ant** first_ant, t_room *start)
{
	size_t	i;
	void **v_vector;
	if (*ants <= 0)
		return ;
	i = 0;
	v_vector = start->links.data;
	while (i < start->links.size && *ants > 0)
	{
		if (((t_room*)v_vector[i])->path_index >= 0)
		{
			make_ant(*ant_index, first_ant, ((t_room*)v_vector[i]));
			(*ant_index)++;
			(*ants)--;
		}
		i++;
	}	
}


t_ant *delete_ant(t_ant *ant, t_ant **first_ant)
{
	t_ant* to_return;

	if (ant == NULL)
		return (NULL);
	if (ant->prev_ant != NULL)
		ant->prev_ant->next_ant = ant->next_ant;
	to_return = ant->next_ant;
	if (ant->next_ant != NULL)
		ant->next_ant->prev_ant = 0;
	if (ant == *first_ant)
		*first_ant = to_return;
	ft_memdel((void **)&ant);
	return (to_return);
}

void move_now_ants(t_ant *ant, t_ant **first_ant, t_room *end)
{
	int need_whitespace;

	need_whitespace = 0;
	while (ant)
	{
		if (ant->to_delete)
		{
			ant = delete_ant(ant, first_ant);
			continue ;
		}
		if (need_whitespace)
			write(1, " ", 1);
		need_whitespace = 1;
		write(1, "L", 1);
		ft_putnbr(ant->ant_index);
		write(1, "-", 1);
		ft_putstr(ant->now_room->name);
		if (ant->now_room == end)
			ant->to_delete = 1;
		ant->now_room = ant->now_room->next_on_path;
		ant = ant->next_ant;
	}
}


void run_ants_print_answer(t_data *data)
{
	t_ant	*first_ant;
	int		ant_index;
	
	first_ant = 0;
	ant_index = 1;
	while(data->ants > 0 || first_ant)
	{
		create_now_ants(&data->ants, &ant_index, &first_ant, data->start);
		move_now_ants(first_ant, &first_ant, data->end);
		if (data->ants > 0 || first_ant)
			write(1, "\n", 1);
	}
}