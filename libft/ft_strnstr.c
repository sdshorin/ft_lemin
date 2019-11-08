/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:08:24 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *hhaystack, char *needle, size_t cur, size_t len)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (needle[i] == hhaystack[i] && (cur + i < len))
			i++;
		else
			return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*hhaystack;
	char	*nneedle;

	nneedle = (char *)needle;
	hhaystack = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (hhaystack);
	while (hhaystack[i] != '\0' && i < len)
	{
		if (hhaystack[i] != *nneedle)
			i++;
		else if (check(&(hhaystack[i]), nneedle, i, len) == 1)
			return (&(hhaystack[i]));
		else
			i++;
	}
	return (NULL);
}
