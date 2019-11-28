/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_queue_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:49:39 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/28 19:49:40 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_void_queue_init(t_void_queue *int_queue)
{
	int_queue->size = 0;
	int_queue->capacity = 16;
	int_queue->start = 0;
	int_queue->data = (void**)malloc(int_queue->capacity * sizeof(void*));
	if (!int_queue->data)
		return (1);
	return (0);
}
