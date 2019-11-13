//
// Created by Katharine Psylocke on 13/11/2019.
//

#include "lemin.h"

static t_input	*create_input_node(char *str, int number)
{
	t_input	*list;

	if ((list = (t_input *)malloc(sizeof(t_input))) == NULL)
		error_handler("Allocation error in create_input_list!");
	list->str = str;
	list->next = NULL;
	return (list);
}

void			get_input(char *str, t_data *data)
{
	t_input	*cur;
	size_t	number;

	number = 0;
	cur = data->input_tail;
	if (cur == NULL)
	{
		data->input_head = create_input_node(str, 0);
		data->input_tail = data->input_head;
	}
	else
	{
		cur->next = create_input_node(str, number);
		data->input_tail = cur->next;
	}
	data->input_strings++;
}

void			display_input(t_data *data)
{
	t_input	*input;
	t_input *prev;

	input = data->input_head;
	while (input != NULL)
	{
		ft_putendl(input->str);
		prev = input;
		input = input->next;
		free(prev->str);
		free(prev);
	}
	ft_putchar_fd(0,'\n');
}
