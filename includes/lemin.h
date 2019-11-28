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

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

typedef struct	s_input
{
	char			*str;
	struct s_input	*next;
}				t_input;

typedef struct	s_recipe
{
	int				path_cost;
	t_int_vector	used_old_paths;
	t_void_vector	start_old_path_room;
}				t_recipe;

typedef struct	s_room
{
	int				index;
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
	int				level;
	int				q_links;
	struct s_room	*next_on_path;
	struct s_room	*recipe_come_from;
	int				path_index;
	t_void_vector	links;
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
	int			ants;
	int			q_rooms;
	t_room		*first;
	t_room		*start;
	t_room		*end;
	size_t		path_quantity;
	int			sum_path_len;
	int			max_path_cost;
	t_input		*input_head;
	t_input		*input_tail;
	int			fd;
	int			add_direct_path;

}				t_data;

typedef struct	s_ant
{
	t_room			*now_room;
	int				ant_index;
	int				to_delete;
	struct s_ant	*next_ant;
	struct s_ant	*prev_ant;
}				t_ant;

void			get_input(char *str, t_data *data);
void			display_input(t_data *data);
t_data			*create_data_struct(void);
void			display_debug_data(t_data *data);
void			destroy_data(t_data *data);
t_data			*get_data(t_data *data);
void			get_ants(t_data *data);
void			get_room(char *str, t_data *data, int *comm);
int				get_link(char *str, t_data *data);
int				read_comments(t_data *data, char **str);
void			error_handler(char *message, t_data *data);
void			init_queue(t_queue *queue);
void			add_to_queue(t_queue *queue, t_room *room, t_room *come_from);
t_room			*get_from_queue(t_queue *queue);
int				lem_in_find_paths(t_data *data);
void			run_ants_print_answer(t_data *data);
void			handle_direct_path(t_data *data);
int				make_recipe_step_back(t_room *prev_room,
									t_room *room, t_queue *queue);
int				make_recipe(t_room *prev_room, t_room *room, t_queue *queue);
void			count_new_max_path_cost(t_data *data);
void			add_start(t_queue *queue, t_data *data);
int				find_new_way(t_data *data);
void			make_new_way(t_data *data);
void			make_ant(int ant_index, t_ant **first_ant, t_room *next_room,
						t_ant **last_ant);
void			move_now_ants(t_ant **first_ant, t_ant **last_ant);
void			sort_paths(t_data *data);
void			create_now_ants(t_data *data, int *ant_index, t_ant **first_ant,
					t_ant **last_ant);

#endif
