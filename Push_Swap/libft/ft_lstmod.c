/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:57:01 by fwmoor            #+#    #+#             */
/*   Updated: 2019/09/02 08:11:42 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *head;

	list = NULL;
	if (lst && f)
	{
		head = f(lst);
		list = head;
		lst = lst->next;
		while (lst)
		{
			head->next = f(lst);
			head = head->next;
			lst = lst->next;
		}
	}
	return (list);
}
