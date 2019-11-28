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
		ft_memdel((void **)&cur->links.data);
		ft_memdel((void **)&cur->recipe.used_old_paths.data);
		ft_void_vector_free(&cur->recipe.start_old_path_room);
		prev = cur;
		cur = cur->next;
		ft_memdel((void **)&prev);
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
