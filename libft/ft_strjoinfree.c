/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:03:05 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/13 16:06:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*result;

	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(*s1);
	s2len = ft_strlen(s2);
	result = ft_strnew(s1len + s2len + 1);
	if (result == NULL)
	{
		free(*s1);
		return (NULL);
	}
	ft_strcpy(result, *s1);
	ft_strcpy(&(result[s1len]), s2);
	free(*s1);
	return (result);
}
