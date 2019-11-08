/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:14:56 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t i;
	size_t words;

	words = 0;
	i = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		words++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (words);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char		**words(char const **s, char c, char **result, size_t *word)
{
	size_t	wordi;

	result[*word] = (char *)malloc(word_len(*s, c) + 1);
	if (result[*word] == NULL)
	{
		while (*word-- > 0)
			free(result[*word]);
		free(result);
		return (NULL);
	}
	wordi = 0;
	while (**s != c && **s != '\0')
	{
		result[*word][wordi] = **s;
		*s += 1;
		wordi++;
	}
	result[*word][wordi] = '\0';
	*word = *word + 1;
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	words_cnt;
	size_t	word;

	words_cnt = count_words(s, c);
	if (s == NULL)
		return (NULL);
	if ((result = (char **)malloc(sizeof(char *) * (words_cnt + 1))) == NULL)
		return (NULL);
	result[words_cnt] = NULL;
	word = 0;
	while (s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		if ((result = words(&s, c, result, &word)) == NULL)
			return (NULL);
		if (*s != '\0')
			s++;
	}
	if (words_cnt == 0)
		result[0] = NULL;
	return (result);
}
