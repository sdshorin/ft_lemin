//
// Created by Katharine Psylocke on 08/11/2019.
//

#include "libft.h"

int	ft_numlen(const char *str)
{
	int len;

	len = 0;
	while (*str != '\0' && ft_isdigit(*str) == 0)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
	while (*str == '0')
		str++;
	while (str[len] != '\0' && ft_isdigit(str[len]) == 1)
		len++;
	return (len);
}