/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:48:18 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int result;
	int neg;

	neg = 1;
	result = 0;
	if (n < 0)
	{
		result++;
		neg = -1;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n /= 10;
	}
	return (result * neg);
}

static void	invert(int *len, int *neg, int *n)
{
	if (*len < 0)
	{
		*len *= -1;
		*neg = -1;
		*n *= -1;
	}
}

char		*ft_itoa(int n)
{
	char	*result;
	int		neg;
	int		len;

	neg = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_digits(n);
	invert(&len, &neg, &n);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	while (len-- > 0)
	{
		if (neg == -1 && len == 0)
		{
			result[len] = '-';
			break ;
		}
		result[len] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
