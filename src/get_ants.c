/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:02:49 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:02:51 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_ants(t_data *data)
{
	char	*str;
	int		len;
	int		result;

	while (get_next_line(data->fd, &str))
	{
		if (str[0] == '\n' || str[0] == '\0' ||
								(str[0] != '#' && !ft_isdigit(str[0])))
			error_handler("Cannot read ants!", data);
		if (str[0] == '#' && read_comments(data, &str) != 10)
			continue ;
		result = ft_atoi(str);
		len = ft_numlen(str);
		get_input(str, data);
		if (result <= 0 || (result == 1 && len > 1))
			error_handler("Ants number invalid!", data);
		data->ants = result;
		return ;
	}
}
