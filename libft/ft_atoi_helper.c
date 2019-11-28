/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:03:36 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 20:03:58 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_last(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (*s ? 1 : 0);
}

static void	calc_offset(const char **s, int *len, int *neg)
{
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*neg += 1;
		*s += 1;
	}
	if (**s == '0')
	{
		while (**s == '0')
			*s += 1;
		*len += 1;
	}
}

int			ft_atoi_helper(const char *s, int sign, int last)
{
	int len;
	int neg;

	neg = 0;
	len = 0;
	if (!s)
		return (0);
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if ((sign == -1 && *s != '-') || (sign == 1 && *s == '-'))
		return (0);
	calc_offset(&s, &len, &neg);
	if (ft_isdigit(*s) && !len && s++)
		len += 1 + neg;
	else if (ft_isdigit(*s) && s++)
		len += neg;
	while (ft_isdigit(*s))
	{
		len++;
		s++;
	}
	if (last && ft_check_last(s))
		return (0);
	return (len == ft_numlen(s));
}
