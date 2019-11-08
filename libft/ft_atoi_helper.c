//
// Created by Katharine Psylocke on 08/11/2019.
//

#include "libft.h"

static int	ft_check_last(const char *s)
{
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	return (*s ? 1 : 0);
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
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			neg++;
		s++;
	}
	if (*s == '0')
	{
		while (*s == '0')
			s++;
		len++;
	}
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