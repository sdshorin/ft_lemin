//
// Created by Katharine Psylocke on 13/11/2019.
//

#include "lemin.h"

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
		get_input(str, data);
		if (result <= 0 || (result == 1 && len > 1))
			error_handler("Ants number invalid!");
		data->ants = result;
		return ;
	}
}
