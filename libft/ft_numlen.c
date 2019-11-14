//
// Created by Katharine Psylocke on 08/11/2019.
//

#include "libft.h"

int	ft_numlen(const char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) == 0)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i + len] != '\0' && ft_isdigit(str[i + len]) == 1)
		len++;
	if (len == 0 && ft_atoi(str) == 0)
		len++;
	return (len);
}