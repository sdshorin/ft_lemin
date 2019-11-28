/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ants_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:03:46 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/28 20:03:47 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	handle_direct_path(t_data *data)
{
	t_ant	*first_ant;
	t_ant	*last_ant;
	int		i;
	t_room	*end;

	i = 1;
	end = data->end;
	first_ant = 0;
	last_ant = 0;
	while (i <= data->ants)
	{
		make_ant(i, &first_ant, end, &last_ant);
		i++;
	}
	move_now_ants(&first_ant, &last_ant);
	write(1, "\n", 1);
}

void	run_ants_print_answer(t_data *data)
{
	t_ant	*first_ant;
	t_ant	*last_ant;
	int		ant_index;

	first_ant = 0;
	ant_index = 1;
	last_ant = 0;
	sort_paths(data);
	while (data->ants > 0 || first_ant)
	{
		create_now_ants(data, &ant_index, &first_ant, &last_ant);
		move_now_ants(&first_ant, &last_ant);
		write(1, "\n", 1);
	}
}
