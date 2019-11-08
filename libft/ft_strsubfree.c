/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:56:04 by kpsylock          #+#    #+#             */
/*   Updated: 2019/09/20 13:57:30 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char **s, unsigned int start, size_t len)
{
	char *result;

	if (s != NULL && (len + 1) != 0)
	{
		result = malloc(sizeof(char) * (len + 1));
		if (result == NULL)
			return (NULL);
		result = ft_strncpy(result, (*s + start), len);
		result[len] = '\0';
		free(*s);
		return (result);
	}
	return (NULL);
}
