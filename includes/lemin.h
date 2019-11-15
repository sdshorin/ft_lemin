/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:04:26 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/14 19:04:28 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef struct	s_input
{ // does we need it?
	//This struct needed to put input to output
	char 			*str;
	struct s_input	*next;
}				t_input;

typedef struct	s_recipe
{
	int 			path_cost;
	int				need_init_vector;
	t_int_vector	used_old_pathes;
}				t_recipe;


typedef struct	s_room
{
	int 			index;
	char			*name; // room name
	int 			x;
	int 			y;
	struct s_room	*next; //temp
	int 			level; // distance from the star
	int 			q_links; // amount of links
	// struct s_room	**links; // links
	
	struct s_room	*next_on_path; //temp
	struct s_room	*prev_on_path; //temp
	int				path_index;
	t_void_vector	*links;
	t_recipe		recipe;
	struct s_room	*next_in_queue;
	struct s_room	*prev_in_queue;
}				t_room;

typedef struct	s_queue
{
	t_room			*start;
	t_room			*finish;

}				t_queue;

typedef struct	s_data
{
	int 		ants; // amount of ants

	int 		q_rooms; // amount of rooms
	t_room		*first; //first by order of reading

	t_room 		*start;
	t_room		*end;

	int 		*path; // ?

	int			path_quantity; // now quantity of path 

	t_input		*input_head;
	t_input		*input_tail;
}				t_data;

void			get_input(char *str, t_data *data);
void			display_input(t_data *data);

t_data			*create_data_struct(void);
void			display_debug_data(t_data *data);
void			destroy_data(t_data *data);


t_data 			*get_data(t_data *data);
void			get_ants(t_data *data);
void			get_room(char *str, t_data *data, int *comm);
int				get_link(char *str, t_data *data);

int				read_comments(t_data *data, char **str);


void			error_handler(char *message, t_data *data);







#endif
