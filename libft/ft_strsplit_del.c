/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:25:54 by bjesse            #+#    #+#             */
/*   Updated: 2019/11/30 18:25:55 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsplit_del(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&(str[i]));
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (-1);
}
