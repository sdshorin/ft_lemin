/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:41:33 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/31 18:42:20 by kpsylock         ###   ########.fr       */
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

long long int			ft_strtol(const char *str)
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
		if ((i - offset) >= 19 && result != 0)
			return (negativity == -1 ? 0 : -1);
		result = (result * 10) + (long long int)(str[i] - '0');
		i++;
		if (result > 9223372036854775807)
			return (negativity == -1 ? 0 : -1);
	}
	return (result * negativity);
}
