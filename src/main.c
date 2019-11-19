/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:32 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:34 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	error_handler(char *message, t_data *data)
{
	get_next_line(0, NULL, -1);
	if (data != NULL)
		destroy_data(data);
	ft_putendl_fd(message, 2);
	exit(1);
}

int		main(void)
{
	t_data	*data;

	data = create_data_struct();
	get_data(data);
	if (data->start == data->end)
		error_handler("Error: start == end!", data);
	display_input(data);
	display_debug_data(data);
	lem_in_find_paths(data);
	run_ants_print_answer(data);

	destroy_data(data);
	return (0);
}
