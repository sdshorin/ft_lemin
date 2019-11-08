/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:19:19 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*result;

	lenght = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (lenght + 1));
	if (result == NULL)
		return (NULL);
	result = ft_strcpy(result, s1);
	return (result);
}
