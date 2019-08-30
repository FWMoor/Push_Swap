/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fremoor <fremoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 08:15:29 by fremoor           #+#    #+#             */
/*   Updated: 2019/08/30 12:28:22 by fremoor          ###   ########.fr       */
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

void		rotate_x(t_stack **h, char c, int pos)
{
	int		size;

	size = list_size(*h);
	if (pos > size / 2)
	{
		pos = size - pos;
		while (pos != 0)
		{
			(c == 'a') ? rev_rotate(h, 1, "rra") : rev_rotate(h, 1, "rrb");
			pos--;
		}
	}
	else if (pos <= size / 2)
	{
		while (pos != 0)
		{
			(c == 'a') ? rotate(h, 1, "ra") : rotate(h, 1, "rb");
			pos--;
		}
	}
}

void		push_b(t_stack **a, t_stack **b, int i, int max)
{
	int		pos;

	while (*b)
	{
		while (i > 0 && i >= max - 5)
		{
			pos = large_pos(b, large_num(b));
			rotate_x(b, 'b', pos);
			push(a, b, 1, "pa");
			i--;
		}
		max -= 5;
	}
}

void		sort_larger(t_stack **stacka, t_stack **stackb)
{
	int		i;
	int		max;

	max = 0;
	i = 1;
	while (*stacka)
	{
		max += 44;
		while (i <= max)
		{
			if (!(*stacka))
				break;
			if ((*stacka)->norm <= max)
			{
				push(stackb, stacka, 1, "pb");
				i++;
			}
			else
				rotate(stacka, 1, "ra");
		}
	}
	i--;
	push_b(stacka, stackb, i, max);
}
