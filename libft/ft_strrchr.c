/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:22:32 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char cc;
	char *result;

	cc = (char)c;
	result = (char *)s;
	while (*result != '\0')
		result++;
	while (result != s)
	{
		if (*result == cc)
			return (result);
		result--;
	}
	if (*result == cc)
		return (result);
	return (NULL);
}
