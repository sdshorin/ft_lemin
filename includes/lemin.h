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




typedef struct	t_map
{
	int 		ants;

	int 		q_rooms;
	char 		**n_rooms;
	char 		*links;
	int 		**tab;

	int 		*path;

}				s_map;

int get_ants(char *str);
int get_data(s_map *data);

#endif
