/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:56:02 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/18 19:56:28 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxt_lst;

	lst = *alst;
	while (lst)
	{
		nxt_lst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxt_lst;
	}
	*alst = NULL;
}

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *n_list;

	if (!(n_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		n_list->content = NULL;
		n_list->content_size = 0;
	}
	else
	{
		n_list->content = malloc(content_size);
		if (n_list->content == NULL)
		{
			free(n_list);
			return (NULL);
		}
		ft_memcpy(n_list->content, content, content_size);
		n_list->content_size = content_size;
	}
	n_list->next = NULL;
	return (n_list);
}
