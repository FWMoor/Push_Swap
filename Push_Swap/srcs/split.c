/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 08:15:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/09/02 08:13:30 by fremoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rotate_x(t_stack **h, char c, int pos)
{
	int		size;

	size = list_size(*h);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos-- != 0)
			(c == 'a') ? rev_rotate(h, 1, "rra") : rev_rotate(h, 1, "rrb");
	}
	else if (pos <= size / 2)
	{
		while (pos-- != 0)
			(c == 'a') ? rotate(h, 1, "ra") : rotate(h, 1, "rb");
	}
}

void		push_b(t_stack **a, t_stack **b, int i, int max)
{
	int		pos;

	while (*b)
	{
		while (i > 0 && i >= max - 5)
		{
			pos = large_pos(b, i);
			rotate_x(b, 'b', pos);
			push(a, b, 1, "pa");
			i--;
		}
		max -= 5;
	}
}

void		push_small(t_stack **stacka, t_stack **stackb, int pos)
{
	int		len;

	len = list_size(*stacka);
	if (pos > len / 2)
	{
		pos = len - pos;
		while (pos-- != 0)
			rev_rotate(stacka, 1, "rra");
	}
	else if (pos <= len / 2)
	{
		while (pos-- != 0)
			rotate(stacka, 1, "ra");
	}
	push(stackb, stacka, 1, "pb");
}

void		norm(t_stack **stacka)
{
	int		n;
	t_stack *slow;
	t_stack	*fast;

	slow = *stacka;
	while (slow)
	{
		n = list_size(*stacka);
		slow->norm = n;
		fast = *stacka;
		while (fast)
		{
			if (slow->val < fast->val)
				slow->norm--;
			fast = fast->next;
		}
		slow = slow->next;
	}
}
