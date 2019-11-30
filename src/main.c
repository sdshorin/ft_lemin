/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:32 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:34 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>

void	error_handler(char *message, t_data *data)
{
	if (data != NULL)
	{
		get_next_line(data->fd, NULL);
		destroy_data(data);
	}
	ft_putendl_fd(message, 2);
	exit(1);
}

void	lem_in_main(t_data *data)
{
	if (ft_void_vector_search(&(data->start->links), data->end) >= 0)
		handle_direct_path(data);
	else
		run_ants_print_answer(data);
}

int		is_regular_file(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}

void	read_from_file(char *path, t_data *data)
{
	ft_putendl("Trying to read graph from file...");
	if (!is_regular_file(path))
	{
		ft_putendl("First arg isn't file!");
		ft_putendl("Trying to read from stdin...");
		return ;
	}
	data->fd = open(path, O_RDONLY);
	if (data->fd < 0 || read(data->fd, NULL, 0) < 0)
	{
		ft_putendl("Cannot open file specified in first arg!");
		ft_putendl("Trying to read from stdin...");
		data->fd = 0;
	}
}

int		main(int argc, char **argv)
{
	t_data	*data;

	data = create_data_struct();
	if (argc > 1)
		read_from_file(argv[1], data);
	get_data(data);
	if (!data->first)
		error_handler("Error: no rooms!", data);
	if (!data->start || !data->end)
		error_handler("Error: start or end doesn't define!", data);
	if (data->start == data->end)
		error_handler("Error: start == end!", data);
	lem_in_find_paths(data);
	if (data->path_quantity == 0)
		error_handler("Error: no path!!", data);
	display_input(data);
	lem_in_main(data);
	destroy_data(data);
	return (0);
}
