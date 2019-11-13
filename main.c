#include "lemin.h"

void	error_handler(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}


int main(void)
{
	t_data	*data;

	data = create_data_struct();
	get_data(data);
	display_input(data);
	if (data->start == data->end)
		ft_putendl_fd("Error: start == end!", 2);

	debug_display_data(data);
	destroy_data(data);
	return 0;
}