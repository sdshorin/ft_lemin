/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:34:44 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	trim_start;
	size_t	trim_len;
	size_t	trim_stop;
	char	*result;

	if (s == NULL)
		return (NULL);
	trim_start = 0;
	while (s[trim_start] != '\0' && is_whitespace(s[trim_start]) == 1)
		trim_start++;
	trim_stop = ft_strlen(s) - 1;
	while (is_whitespace(s[trim_stop]) == 1 && trim_stop > trim_start)
		trim_stop--;
	trim_len = trim_stop - trim_start + 1;
	if (trim_len == 0)
		return (ft_strnew(1));
	result = ft_strsub(s, trim_start, trim_len);
	return (result);
}
