
#include "lemin.h"




void make_ant(int ant_index, t_ant **first_ant, t_room *next_room,
		t_ant **last_ant)
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


void create_now_ants(t_data *data, int *ant_index, t_ant** first_ant,
		t_ant** last_ant)
{
	size_t	i;
	void	**v_vector;
	t_room	*now;

	if (data->ants <= 0)
		return ;
	i = 0;
	v_vector = data->start->links.data;
	while (i < data->start->links.size && data->ants > 0)
	{
		now = v_vector[i];
		if (now->path_index >= 0 || now == data->end)
		{
			if (now->recipe.path_cost >= data->max_path_cost + 2 && i++)
				continue;
			make_ant(*ant_index, first_ant, now, last_ant);
			if (now != data->end)
				now->recipe.path_cost++;
			(*ant_index)++;
			data->ants--;
		}
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

	return (to_return);
}




void move_now_ants(t_ant **first_ant, t_ant **last_ant)
{
	int		need_whitespace;
	t_ant	*ant;

	ant = *first_ant;
	need_whitespace = 0;
	while (ant)
	{

		if (need_whitespace)
			write(1, " ", 1);
		need_whitespace = 1;
		write(1, "L", 1);
		ft_putnbr(ant->ant_index);
		write(1, "-", 1);
		ft_putstr(ant->now_room->name);
		ant->now_room = ant->now_room->next_on_path;
		if (!ant->now_room)
			ant = delete_ant(ant, first_ant, last_ant);
		else
			ant = ant->next_ant;
	}
}