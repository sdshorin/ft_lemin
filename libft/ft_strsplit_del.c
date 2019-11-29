//
// Created by Katharine Psylocke on 29/11/2019.
//

#include "libft.h"

int	ft_strsplit_del(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&(str[i]));
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (-1);
}