/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:02:25 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:02:30 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lemin.h"

void	display_debug_data(t_data *data)
{
	int		j;
	t_room	*room;

	j = 0;
	printf("Ants: %d\n", data->ants);
	room = data->first;
	while (room != NULL)
	{
		if (data->start == room)
			printf("##start\n");
		else if (data->end == room)
			printf("##end\n");
		printf("Room: %s\n", room->name);
		printf("It's coords: x = %d y = %d\n", room->x, room->y);
		printf("It's links:\n");
		while (j < room->q_links)
		{
//			printf(" Link #%d name: %s\n", j, room->links[j].name);
			j++;
			printf("nothing :c");
		}
		printf("\n");
		j = 0;
		room = room->next;
	}
}
