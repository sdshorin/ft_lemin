/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpsylock <kpsylock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:11:42 by kpsylock          #+#    #+#             */
/*   Updated: 2019/10/15 14:48:24 by kpsylock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		remove_list(t_list *lst)
{
	t_list	temp;

	while (lst != NULL)
	{
		temp.next = lst->next;
		free(lst->content);
		free(lst);
		lst = temp.next;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	if (new == NULL)
		return (NULL);
	lst = lst->next;
	temp = new;
	while (lst)
	{
		new->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!(new->next))
		{
			remove_list(temp);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (temp);
}
