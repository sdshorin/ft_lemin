/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:46:58 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/13 16:06:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long long int n)
{
	int result;

	result = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char		*ft_ulltoa(unsigned long long int n)
{
	char			*result;
	int				len;

	n = (unsigned long long int)n;
	len = count_digits(n);
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	while (len-- > 0)
	{
		result[len] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}
