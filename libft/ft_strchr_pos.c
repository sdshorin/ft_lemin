/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:09:01 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 20:09:26 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_pos(const char *str, int c)
{
	int		pos;
	char	cc;
	char	*temp;

	pos = 0;
	temp = (char *)str;
	cc = (char)c;
	while (str[pos] != '\0')
	{
		if (str[pos] == cc)
			return (pos);
		pos++;
	}
	if (str[pos] == cc)
		return (pos);
	return (-1);
}
