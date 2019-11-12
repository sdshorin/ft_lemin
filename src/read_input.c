//
// Created by Katharine Psylocke on 07/11/2019.
//

#include "lemin.h"

void	error_handler(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
t_input		*create_input_struct(char *str, int number)
{
	t_input	*list;

	if (!(list = (t_input *)malloc(sizeof(t_input))))
		error_handler("Allocation error in create_input_list!");
	list->str = str;
	list->next = NULL;
	return (list);
}
#pragma clang diagnostic pop

void	write_input(char *str, t_data *data)
{
	t_input	*cur;
	size_t	number;

	number = 0;
	cur = data->input_tail;
	if (cur == NULL)
	{
		data->input_head = create_input_struct(str, 0);
		data->input_tail = data->input_head;
	}
	else
	{
		cur->next = create_input_struct(str, number);
		data->input_tail = cur->next;
	}
	data->input_strings++;
}

void	get_ants(t_data *data)
{
	char	*str;
	int		len;
	int		result;

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
		write_input(str, data);
//		free(str);
		if (result <= 0 || (result == 1 && len > 1))
			error_handler("Ants number invalid!");
		data->ants = result;
		return ;
	}
}


void	get_room(char *str, t_data *data, int *comm)
{
	static t_room	*last;

	write_input(str, data);
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
	if (*comm == 1)
		data->start = last;
	else if (*comm == -1)
		data->end = last;
	*comm = 0;
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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"

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

#pragma clang diagnostic pop

static int	get_link(char *str, t_data *data)
{
	t_room	*room1;
	t_room	*room2;
	char 	*name1;
	int 	n2len;
	char 	*name2;

	write_input(str, data);
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

static int	mode_switcher(t_data *data)
{
	if (data->start == NULL || data->end == NULL)
		error_handler("No start/end mark!");
	return (1);
}

static int read_comments(t_data *data, char **str)
{
	int comm;

	comm = 0;
	write_input(*str, data);
	if (str[1] != '\0')
	{
		if (ft_strequ(&((*str)[2]), "start"))
			comm = 1;
		else if (ft_strequ(&((*str)[2]), "end"))
			comm = -1;
	}
//	ft_strdel(str);
	return (comm);
}

static t_data *finish_reading(t_data *data, char **str)
{
	get_next_line(0, str, -1);
	ft_strdel(str);
	return (data);
}



t_data *get_data(t_data *data)
{
	char	*str;
	int		mode;
	int 	comm;

	mode = 0;
	comm = 0;
	get_ants(data);
	while (get_next_line(0, &str, 0) > 0)
	{
		if (str[0] == 'L')
			error_handler("Room name should not start with 'L'!");
		if (mode == -1 || str[0] == '\n' || str[0] == '\0')
			return (finish_reading(data, &str));
		if (str[0] == '#' && (comm = read_comments(data, &str)) < 10)
			continue ;
		if (mode == 0 && ft_strchr(str, '-') != NULL)
			mode = mode_switcher(data);
		mode == 0 ? get_room(str, data, &comm) : (mode = get_link(str, data));
//		ft_strdel(&str);
	}
	return (data);
}
