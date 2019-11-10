//
// Created by Katharine Psylocke on 07/11/2019.
//

#include "lemin.h"



void	error_handler(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void get_ants(t_data *data)
{
	char	*str;
	int		len;
	int		result;

	str = NULL;
	while (get_next_line(0, &str, 0))
	{
		if (str[0] == '\n' || str[0] == '\0')
			error_handler("Cannot read ants!");
		if (str[0] == '#')
		{
			ft_strdel(&str);
			continue ;
		}
		result = ft_atoi(str);
		len = ft_numlen(str);
		free(str);
		if (result <= 0)
			error_handler("Ants number negative!");
		else if (result == 1 && len > 1)
			error_handler("Ants number invalid!");
		else
			data->ants = result;
	}
}


void	get_room(char *str, t_data *data, int *command)
{
	static t_room	*last;

	if (data->first == NULL)
	{
		data->first = create_room(str, data);
		last = data->first;
	}
	else
	{
		while (last->next_room != NULL)
			last = last->next_room;
		last->next_room = create_room(str, data);
		last = last->next_room;
	}
	data->q_rooms++;
	if (*command == 1)
		data->start = last;
	else if (*command == -1)
		data->end = last;
	*command = 0;
}

static t_room *match_name(char *name, t_room *room)
{
	while (room != NULL)
	{
		if (ft_strequ(room->name, name))
			return (room);
		room = room->next_room;
	}
	error_handler("No such room!");
}

void		add_link(t_room *link_dst, t_room *link_src)
{
	t_room	**result;
	int 	n_links;
	int		i;

	n_links = link_src->n_links;
	if (!(result = (t_room **)malloc(sizeof(t_room *) * (n_links + 1))))
		error_handler("Allocation error in add_link!");
	i = 0;
	while (i < n_links)
	{
		result[i] = link_src->links[i];
		i++;
	}
	result[i] = link_dst;
	free(link_src->links);
	link_src->links = result;
	link_src->n_links++;
}

void	get_link(char *str, t_data *data)
{
	t_room	*room1;
	t_room	*room2;
	char 	*name1;
	int 	n2len;
	char 	*name2;

	name1 = ft_strsub(str, 0, ft_strchr_pos(str, '-'));
	n2len = ft_strlen(ft_strchr(str, '-') + 1);
	name2 = ft_strsub(str, ft_strchr_pos(str, '-') + 1, n2len);
	room1 = match_name(name1, data->first);
	room2 = match_name(name2, data->first);
	if (room1 == room2)
		error_handler("Invalid link!");
	add_link(room2, room1);
	add_link(room1, room2);
}

t_data *get_data(t_data *data)
{
	char	*str;
	int		mode;
	int 	command;

	str = NULL;
	mode = 0;
	get_ants(data);
	command = 0;
	while (get_next_line(0, &str, 0) > 0)
	{
		if (str[0] == 'L')
			error_handler("Room name should not start with 'L'!");
		if (str[0] == '\n' || str[0] == '\0')
		{
			get_next_line(0, &str, -1);
			ft_strdel(&str);
			break ;
		}
		if (str[0] == '#')
		{
			if (str[1] != '\0')
			{
				if (ft_strequ(&(str[2]), "start"))
					command = 1;
				else if (ft_strequ(&(str[2]), "end"))
					command = -1;
			}
			ft_strdel(&str);
			continue ;
		}
		if (mode == 0 && ft_strchr_bool(str, '-') == '1')
		{
			if (data->start == NULL || data->end == NULL)
				error_handler("No start/stop mark!");
			if (command != 0)
				error_handler("Invalid start/stop mark!");
			mode = 1;
		}
		if (mode == 0)
			get_room(str, data, &command);
		if (mode == 1)
			get_link(str, data);
		ft_strdel(&str);
	}
	return (data);
}
