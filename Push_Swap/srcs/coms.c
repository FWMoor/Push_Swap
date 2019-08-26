/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwmoor <fwmoor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:27:55 by fwmoor            #+#    #+#             */
/*   Updated: 2019/08/26 21:23:14 by fwmoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		swap(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	if (temp && temp->next)
	{
		i = temp->val;
		temp->val = temp->next->val;
		temp->next->val = i;
	}
}

void		rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if ((!*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	first->prev = last;
}

void		rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*prev;

	if ((!*stack) || !(*stack)->next)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	*stack = last;
}

void		push(t_stack **to, t_stack **from)
{
	t_stack *temp;

	if (!*from)
		return ;
	if (from)
	{
		temp = *from;
		if ((*from)->next)
			*from = (*from)->next;
		else
			*from = NULL;
		if (*from)
			(*from)->prev = NULL;
		if (!to)
			head_add(to, temp);
		else if (to)
			head_add(to, temp);		
	}
}

void		pstack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		ft_printf("%d\n", temp->val);
		temp = temp->next;
	}
}
