/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:40:50 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/05 14:40:55 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c)
{
	char cc;
	char *result;

	result = (char *)s;
	cc = (char)c;
	while (*result != '\0')
	{
		if (*result != cc)
			return (result);
		result++;
	}
	if (*result != cc && *result != '\0')
		return (result);
	return (NULL);
}
