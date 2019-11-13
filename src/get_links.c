//
// Created by Katharine Psylocke on 13/11/2019.
//

#include "lemin.h"

static t_room	*match_name(char *name, t_room *room)
{
	while (room != NULL)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next_room;
	}
	error_handler("No such room!");
}

static void		add_link(t_room *link_dst, t_room *link_src)
{
	t_room	**new;
	int 	n;
	int		i;

	n = link_src->n_links;
	if ((new = (t_room **)malloc(sizeof(t_room *) * (n + 1))) == NULL)
		error_handler("Allocation error in add_link!");
	i = 0;
	while (i < n)
	{
		new[i] = link_src->links[i];
		i++;
	}
	new[i] = link_dst;
	free(link_src->links);
	link_src->links = new;
	link_src->n_links++;
}

int				get_link(char *str, t_data *data)
{
	t_room	*room1;
	t_room	*room2;
	char 	*name1;
	int 	n2len;
	char 	*name2;

	get_input(str, data);
	if (ft_strchr(str, '-') == NULL)
		return (-1);
	name1 = ft_strsub(str, 0, ft_strchr_pos(str, '-'));
	n2len = ft_strlen(ft_strchr(str, '-') + 1);
	name2 = ft_strsub(str, ft_strchr_pos(str, '-') + 1, n2len);
	room1 = match_name(name1, data->first);
	room2 = match_name(name2, data->first);
	ft_strdel(&name1);
	ft_strdel(&name2);
	if (room1 == room2)
		return (1);
	add_link(room2, room1);
	add_link(room1, room2);
	return (1);
}