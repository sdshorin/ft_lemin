/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:44:52 by kpsylock          #+#    #+#             */
/*   Updated: 2019/09/20 20:24:52 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char *tab, char **line)
{
	int i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	*line = ft_strsub(tab, 0, i);
	if (*line == NULL)
		return (-1);
	if (tab[i] != '\0')
		tab = ft_strsubfree(&(tab), i + 1,
			ft_strlen(tab) - i - 1);
	if (*(tab) == '\0')
		ft_strdel(&(tab));
	return (1);
}

static int	read_from_buff(char *buff, char **line, char *tab, const int fd)
{
	if (tab == NULL)
	{
		tab = ft_strdup((const char *)buff);
		if (tab == NULL)
			return (-1);
	}
	else
	{
		tab = ft_strjoinfree(&tab, (const char *)buff);
		if (!tab)
			return (-1);
	}
	if (ft_strchr(tab, '\n') != NULL)
		return (get_line(tab, line, fd));
	return (-2);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*tab;
	int			red;
	int			state;

	if (fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	if (tab != NULL && ft_strchr(tab, '\n') != NULL)
		return (get_line(tab, line));
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		state = read_from_buff(buff, line, tab, fd);
		if (state != -2)
			return (state);
	}
	if (red == 0 && (tab == NULL || tab[0] == '\0'))
		return (0);
	state = get_line(tab, line);
	ft_strdel(&(tab));
	return (state);
}
