/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:07 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:09 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*match_name(char *name, t_room *room, t_data *data)
{
	while (room != NULL)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

static void		add_link(t_room *link_dst, t_room *link_src, t_data *data)
{
	t_room	**new;
	int		n;
	int		i;

	n = link_src->q_links;
	void_vector_push_back(&link_src->links, link_dst);
	// if ((new = (t_room **)malloc(sizeof(t_room *) * (n + 1))) == NULL)
	// 	error_handler("Allocation error in add_link!", data);
	// i = 0;
	// while (i < n)
	// {
	// 	new[i] = link_src->links[i];
	// 	i++;
	// }
	// new[i] = link_dst;
	// free(link_src->links);
	// link_src->links = new;
	link_src->q_links++;
}

int				get_link(char *str, t_data *data)
{
	t_room	*room1;
	t_room	*room2;
	char	*name1;
	int		n2len;
	char	*name2;

	get_input(str, data);
	if (ft_strchr(str, '-') == NULL)
		return (-1);
	name1 = ft_strsub(str, 0, ft_strchr_pos(str, '-'));
	n2len = ft_strlen(ft_strchr(str, '-') + 1);
	name2 = ft_strsub(str, ft_strchr_pos(str, '-') + 1, n2len);
	room1 = match_name(name1, data->first, data);
	room2 = match_name(name2, data->first, data);
	ft_strdel(&name1);
	ft_strdel(&name2);
	if (room1 == NULL || room2 == NULL)
		error_handler("Invalid link!", data);
	if (room1 == room2)
		return (1);
	add_link(room2, room1, data);
	add_link(room1, room2, data);
	return (1);
}
