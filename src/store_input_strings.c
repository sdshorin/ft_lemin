/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input_strings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:03:39 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:03:43 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_input	*create_input_node(char *str, t_data *data)
{
	t_input	*list;

	if ((list = (t_input *)malloc(sizeof(t_input))) == NULL)
		error_handler("Allocation error in create_input_list!", data);
	list->str = str;
	list->next = NULL;
	return (list);
}

void			get_input(char *str, t_data *data)
{
	t_input	*cur;

	cur = data->input_tail;
	if (cur == NULL)
	{
		data->input_head = create_input_node(str, data);
		data->input_tail = data->input_head;
	}
	else
	{
		cur->next = create_input_node(str, data);
		data->input_tail = cur->next;
	}
}

void			display_input(t_data *data)
{
	t_input	*input;

	input = data->input_head;
	while (input != NULL)
	{
		ft_putendl(input->str);
		input = input->next;
	}
	ft_putendl("");
}
