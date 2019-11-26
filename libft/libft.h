/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:57:56 by kpsylock          #+#    #+#             */
/*   Updated: 2019/11/02 19:05:39 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

// # define BUFF_SIZE 1

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_void_vector
{
	size_t	capacity;
	size_t	size;
	void	**data;
}				t_void_vector;

typedef struct	s_int_vector
{
	size_t	capacity;
	size_t	size;
	int		*data;
}				t_int_vector;

typedef struct	s_void_queue
{
	size_t	capacity;
	size_t	size;
	size_t	start;
	void	**data;
}				t_void_queue;

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strnchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isthis(int c, int this);
int				ft_abs(int n);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			*ft_strjoinfree(char **s1, char const *s2);
char			*ft_strjoinfree2(char const *s1, char **s2);
char			*ft_strsubfree(char **s, unsigned int start, size_t len);
char			*ft_lltoa(long long int n);
char			*ft_ulltoa(unsigned long long int n);
char			*ft_ulltoa_base(unsigned long long value, int base, char high);
void			ft_putnstr(char const *s, int len);
long long int	ft_strtol(const char *str);
int				ft_numlen(const char *str);
int				ft_strchr_pos(const char *str, int c);
int				get_next_line(const int fd, char **line);

void			void_vector_free(t_void_vector *v_vector);
int				void_vector_init(t_void_vector *v_vector);
int				void_vector_push_back(t_void_vector *v_vector, void *v);
void			*void_vector_pop_back(t_void_vector *v_vector);
int				void_vector_search(t_void_vector *haystack, void *needle);

void			int_vector_free(t_int_vector *int_vector);
int				int_vector_init(t_int_vector *int_vector);
int				int_vector_push_back(t_int_vector *int_vector, int i);
int				int_vector_pop_back(t_int_vector *int_vector);

void 			int_vector_copy(t_int_vector *dst, t_int_vector *src);

#include <stdio.h> // DELETE
void int_vector_reset(t_int_vector *src);
void int_vector_push_front(t_int_vector *int_vector, int new_num);
void pint_void_vector(t_void_vector *v_vector);
void void_vector_reset(t_void_vector *src);
void 	void_vector_copy(t_void_vector *dst, t_void_vector *src);




void			void_queue_free(t_void_queue *void_queue);
int				void_queue_init(t_void_queue *int_queue);
int 			resize_void_queue(t_void_queue *void_queue);
int				t_void_queue_push(t_void_queue *void_queue, void *v);
void			*void_queue_pop_back(t_void_queue *void_queue);

#endif
