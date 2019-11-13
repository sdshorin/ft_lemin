//
// Created by Katharine Psylocke on 07/11/2019.
//

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef struct	s_input
{
	//This struct needed for showing input in the results of program
	char 			*str;
	struct s_input	*next;
}				t_input;

typedef struct	s_room
{
	char			*name; // room name
	int 			num; // room number
	int 			x;
	int 			y;

	struct s_room	*next_room; //temp

	int 			level; // distance from the start

	int 			n_links; // amount of links
	struct s_room	**links; // links

}				t_room;

typedef struct	s_data
{
	int 		ants; // amount of ants

	int 		q_rooms; // amount of rooms
	t_room		*first; //first by the order of reading

	t_room 		*start;
	t_room		*end;

	int 		*path; // ?

	t_input		*input_head;
	size_t		input_strings;
	t_input		*input_tail;

}				t_data;

void			get_input(char *str, t_data *data);
void			display_input(t_data *data);

t_data			*create_data_struct(void);
void			debug_display_data(t_data *data);
void			destroy_data(t_data *data);


t_data 			*get_data(t_data *data);

//t_room			*create_room(char *str, t_data *data);
void			get_ants(t_data *data);
void			get_room(char *str, t_data *data, int *comm);
int				get_link(char *str, t_data *data);

void			write_input(char *str, t_data *data);

void			error_handler(char *message);







#endif
