//
// Created by Katharine Psylocke on 10/11/2019.
//

#include "libft.h"

char 	ft_strchr_bool(const char *s, int c)
{
	char cc;
	char *result;

	result = (char *)s;
	cc = (char)c;
	while (*result != '\0')
	{
		if (*result == cc)
			return ('1');
		result++;
	}
	if (*result == cc)
		return ('1');
	return ('0');
}