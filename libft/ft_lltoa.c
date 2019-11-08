/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 18:20:05 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/13 16:06:58 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long long int n)
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

static void	invert(int *len, int *neg, long long int *n)
{
	if (*len < 0)
	{
		*len *= -1;
		*neg = -1;
		*n *= -1;
	}
}

char		*ft_lltoa(long long int n)
{
	char			*result;
	int				neg;
	int				len;

	neg = 1;
	if (n + 1 == -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
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
