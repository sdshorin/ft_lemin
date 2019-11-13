//
// Created by Katharine Psylocke on 07/11/2019.
//

#include "lemin.h"

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
	get_input(*str, data);
	if (str[1] != '\0')
	{
		if (ft_strequ(&((*str)[2]), "start"))
			comm = 1;
		else if (ft_strequ(&((*str)[2]), "end"))
			comm = -1;
	}
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
	}
	return (data);
}
