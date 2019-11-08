/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:59:51 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*result;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		result = (char *)malloc(sizeof(char) * (i + 1));
		if (result == NULL)
			return (NULL);
		result[i] = '\0';
		while (i > 0)
		{
			i--;
			result[i] = f(s[i]);
		}
		return (result);
	}
	return (NULL);
}
