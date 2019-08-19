/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:03:10 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/19 11:26:57 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*set_list(int num)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
		return (NULL);
	new->val = num;
	new->next = NULL;
	return (new);
}

void		list_add(t_stack **list, int num)
{
	t_stack	*new;

	new = set_list(num);
	new->next = *list;
	*list = new;
}

void		list_del(t_stack **list)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *list;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*list = NULL;
}
