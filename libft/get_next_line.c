/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:44:52 by kpsylock          #+#    #+#             */
/*   Updated: 2019/09/23 10:59:40 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_errors(char **tab)
{
	if (tab != NULL)
		if (*tab != NULL)
			ft_strdel(tab);
	return (-1);
}

static int	get_line(char **tab, char **line, int fd)
{
	int i;

	i = 0;
	while (tab[fd][i] != '\n' && tab[fd][i] != '\0')
		i++;
	*line = ft_strsub(tab[fd], 0, i);
	if (*line == NULL)
		handle_errors(tab);
	if (tab[fd][i] != '\0')
		tab[fd] = ft_strsubfree(&(tab[fd]), i + 1,
			ft_strlen(tab[fd]) - i - 1);
	if (tab[fd] == NULL)
		handle_errors(tab);
	if (*(tab[fd]) == '\0')
		ft_strdel(&(tab[fd]));
	return (1);
}

static int	read_from_buff(char *buff, char **line, char **tab, const int fd)
{
	if (tab[fd] == NULL)
	{
		tab[fd] = ft_strdup((const char *)buff);
		if (tab[fd] == NULL)
			return (-1);
	}
	else
	{
		tab[fd] = ft_strjoinfree(&(tab[fd]), (const char *)buff);
		if (!tab[fd])
			return (-1);
	}
	if (ft_strchr(tab[fd], '\n') != NULL)
		return (get_line(tab, line, fd));
	return (-2);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*tab[1];
	int			red;
	int			state;

	if (fd < 0 || fd > 12000 || read(fd, NULL, 0) < 0)
		return (-1);
	if (tab[0] != NULL && ft_strchr(tab[0], '\n') != NULL)
		return (get_line(tab, line, 0));
	while ((red = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		state = read_from_buff(buff, line, tab, 0);
		if (state != -2)
			return (state);
	}
	if (red == 0 && (tab[0] == NULL || tab[0][0] == '\0'))
		return (0);
	state = get_line(tab, line, 0);
	ft_strdel(&(tab[0]));
	return (state);
}
