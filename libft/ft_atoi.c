/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:59:12 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				isnonprint(int c)
{
	if (c == '\t' || c == '\v' || c == '\f' ||
		c == '\r' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static long long int	offset_neg(const char *str, int *ext_i)
{
	long long int	negativity;
	int				i;

	i = 0;
	negativity = 1;
	while (isnonprint((int)str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negativity = -1;
		i++;
	}
	*ext_i = i;
	return (negativity);
}

int						ft_atoi(const char *str)
{
	int				i;
	int				offset;
	long long int	result;
	long long int	negativity;

	i = 0;
	negativity = offset_neg(str, &i);
	offset = i;
	result = 0;
	while (ft_isdigit((int)str[i]) == 1)
	{
		if ((i - offset) >= 19)
			return (negativity == -1 ? 0 : -1);
		result = (result * 10) + (long long int)(str[i] - '0');
		i++;
		if (result > 9223372036854775807)
			return (negativity == -1 ? 0 : -1);
	}
	return (result * negativity);
}
