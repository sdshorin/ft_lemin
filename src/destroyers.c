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

t_room		*del_room(t_room *room)
{
	if (room->name != NULL)
		ft_strdel(&(room->name));
	if (room->links.data != NULL)
		ft_memdel((void **)&room->links.data);
	if (room->recipe.used_old_paths.data != NULL)
		ft_memdel((void **)&room->recipe.used_old_paths.data);
	if (room->recipe.start_old_path_room.data != NULL)
		ft_void_vector_free(&room->recipe.start_old_path_room);
	if (room->links.data != NULL)
		ft_void_vector_free(&room->links);
	free(room);
	return (NULL);
}

static void	destroy_rooms(t_data *data)
{
	t_room *cur;
	t_room *next;

	cur = data->first;
	if (cur == NULL)
		return ;
	while (cur != NULL)
	{
		next = cur->next;
		del_room(cur);
		cur = next;
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
		ft_memdel((void **)&prev);
	}
}

void		destroy_data(t_data *data)
{
	if (data != NULL)
	{
		destroy_rooms(data);
		destroy_input(data);
		ft_memdel((void **)&data);
	}
}
