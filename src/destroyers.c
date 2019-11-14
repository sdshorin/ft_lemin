/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:02:37 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:02:39 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	destroy_rooms(t_data *data)
{
	t_room *cur;
	t_room *prev;

	cur = data->first;
	if (cur == NULL)
		return ;
	while (cur != NULL)
	{
		ft_strdel(&(cur->name));
		if (cur->links != NULL)
			free(cur->links);
		cur->links = NULL;
		prev = cur;
		cur = cur->next;
		free(prev);
		prev = NULL;
	}
}

static void	destroy_input(t_data *data)
{
	t_input *cur;
	t_input	*prev;

	cur = data->input_head;
	if (cur == NULL)
		return ;
	while (cur != NULL)
	{
		ft_strdel(&(cur->str));
		prev = cur;
		cur = cur->next;
		free(prev);
		prev = NULL;
	}
}

void		destroy_data(t_data *data)
{
	if (data != NULL)
	{
		get_next_line(0, NULL, -1);
		destroy_rooms(data);
		destroy_input(data);
		free(data);
		data = NULL;
	}
}
