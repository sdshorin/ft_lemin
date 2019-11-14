/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:25 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:26 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_data	*create_data_struct(void)
{
	t_data *data;

	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		error_handler("Allocation error in create_data!", NULL);
	data->ants = -1;
	data->q_rooms = 0;
	data->first = NULL;
	data->start = NULL;
	data->end = NULL;
	data->path = NULL; // ?
	data->input_head = NULL;
	data->input_tail = NULL;
	return (data);
}
