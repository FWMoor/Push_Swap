/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 08:15:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/30 08:54:42 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			is_ordered(t_stack *a)
{
	t_stack	*temp;

	temp = a;
	while (temp && temp->next && temp->val < temp->next->val)
		temp = temp->next;
	if (temp && temp->next)
		return (0);
	return (1);
}

int			get_pivot(t_stack *a)
{
	int		i;
	int		s;
	t_stack	*temp;
	t_stack	*temp2;
	
	s = (list_size(a) <= 400) ? 2 : 7;
	temp = a;
	while (temp->next)
	{
		i = 0;
		temp2 = a;
		while (temp2)
		{
			if (temp2->val < temp->val)
				i++;
			if (i > (list_size(a) + 1) / s)
				break ;
			temp2 = temp2->next;
		} 
		if (i == (list_size(a) + 1) / s)
			break ;
		temp = temp->next;
	}
	return (temp->val);
}

void		opp_rot(t_stack *a, t_stack *b)
{
	int		i;
	int		val;
	t_stack	*temp;

	i = 0;
	val = a->val;
	temp = b->next;
	if (val > b->val && val < last_num(&b))
		return ;
	while (temp && (temp->val > val || temp->prev->val < val))
	{
		i++;
		temp = temp->next;
	}
	if (i > list_size(b) / 2)
		while (b->val > val || last_num(&b) < val)
			rotate(&b, 1, "rb");
	else
		while (b->val > val || last_num(&b) < val)
			rev_rotate(&b, 1, "rrb");
}

void		opp_order(t_stack *b)
{
	int		i;
	t_stack *temp;

	i = 0;
	temp = b;
	if (temp)
	{
		while (temp->next && temp->val > temp->next->val && ++i)
			temp = temp->next;
		if (!temp)
			return ;
		if (i > list_size(b) / 2)
			while (last_num(&b) > b->val)
				rev_rotate(&b, 1, "rrb");
		else
			while (last_num(&b) > b->val)
				rotate(&b, 1, "rb");
	}
}

void		push_b(t_stack *a, t_stack *b)
{
	int		val;
	int		done;
	t_stack	*temp;

	done = 0;
	if (a && a->next)
		if (a->val > a->next->val)
			swap(&a, 1, "sa");
	temp = b;
	val = a->val;
	ft_putendl("hey");
	while (temp && val < temp->val)
		temp = temp->next;
	if (!temp && !done && ++done)
		opp_order(b);
	temp = b;
	while (temp && val > temp->val)
		temp = temp->next;
	if (!temp && !done && ++done)
		opp_order(b);
	if (!done && ++done)
		opp_rot(a, b);
	push(&b, &a, 1, "pb");
}

void		quicksort(t_stack *a, t_stack *b)
{
	int		pivot;
	t_stack	*temp;

	while (!is_ordered(a))
	{
		pivot = get_pivot(a);
		while (a->val < pivot)
			push_b(a, b);
		while (1)
		{
			temp = a;
			while (temp && temp->val >= pivot)
				temp = temp->next;
			if (!temp)
				break ;
			while (a->val < pivot)
				push_b(b, a);
			if (a->next && a->val > a->next->val && a->next->val > pivot)
				swap(&a, 1, "sa");
			(!is_ordered(a)) ? rotate(&a, 1, "sa") : 0;
		}
	}
	opp_order(b);
	while (b)
		push(&a, &b, 1, "pa");
}
