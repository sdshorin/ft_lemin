//
// Created by Katharine Psylocke on 07/11/2019.
//

#include "lemin.h"
/*

*/

int get_ants(char *str)
{
	int	result;

	result = ft_atoi(str);
	if (result <= 0)
		return (-1);
	else if (result == 1 && ft_numlen(str) > 1)
		return (-1);
	else
		return (result);
}
/*
int get_room(t_map data)
{

}
*/

int get_data(t_data *data)
{
	char *str;
	int ret;
	int mode;

	str = NULL;
	ret = 1;
	mode = 0;
	while (get_next_line(0, &str) > 0)
	{
		if (str[0] == '#')
		{
			free(str);
			str = NULL;
			continue ;
		}
		else if (data->ants == -1 && (data->ants = get_ants(str)) < 0)
		{
//			error()
			exit(1);
		}
		else if ()
	}
	return (0);
}
