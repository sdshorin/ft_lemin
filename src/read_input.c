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
int get_room(s_map data)
{

}
*/

int get_data(s_map *data)
{
	char *str;
	int ret;

	str = NULL;
	while (get_next_line(0, &str) > 0)
	{
		printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return (0);
}
