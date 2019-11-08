/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:07:49 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/13 21:41:01 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long long n, int base)
{
	int result;

	result = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n /= base;
	}
	return (result);
}

char		*ft_ulltoa_base(unsigned long long value, int base, char high)
{
	char	*radix;
	char	*result;
	int		len;

	if (high == '1')
		radix = "0123456789ABCDEF";
	else
		radix = "0123456789abcdef";
	value = (unsigned long long)value;
	len = count_digits(value, base);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	return (result);
}
