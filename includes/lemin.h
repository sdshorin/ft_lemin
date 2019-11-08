//
// Created by Katharine Psylocke on 07/11/2019.
//

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"



#include <stdio.h>


typedef struct	s_room
{
	char			*name; // room name
	int 			num; // room number
	struct s_room	*next_num;
	int 			n_links; // amount of links
	struct s_room	**links; // links
}				t_room;

typedef struct	s_data
{
	int 		ants; // amount of ants

	int 		q_rooms; // amount of rooms
	t_room 		*start;
	t_room		*end;

	int 		*path; // ?

}				t_data;

int				get_ants(char *str);
int 			get_data(t_data *data);

#endif
