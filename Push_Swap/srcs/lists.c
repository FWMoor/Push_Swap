/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 11:03:10 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/26 20:19:09 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*add_nodes(int num)
{
	t_stack	*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
		return (NULL);
	new->prev = NULL;
	new->val = num;
	new->next = NULL;
	return (new);
}

void		head_add(t_stack **list, t_stack *node)
{
	t_stack	*temp;

	if (!list || !node)
		return ;
	temp = *list;
	if (temp)
	{
		temp->prev = node;
		node->next = *list;
		node->prev = NULL;
		*list = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		*list = node;
	}
}

void		tail_add(t_stack **list, t_stack *node)
{
	t_stack	*temp;

	if (!list || !node)
		return ;
	temp = *list;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
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

t_stack		*stack_init(char **av)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

	i = 1;
	head = add_nodes(ft_atoi(av[i++]));
	while (av[i])
	{
		node = add_nodes(ft_atoi(av[i++]));
		tail_add(&head, node);
	}
	return (head);
}
